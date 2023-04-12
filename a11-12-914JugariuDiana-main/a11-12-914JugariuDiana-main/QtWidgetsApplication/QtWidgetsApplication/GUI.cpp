#include "GUI.h"
#include <qvboxlayout>
#include <qformlayout.h>
#include <qgridlayout.h>
#include <vector>
#include <qmessagebox.h>
#include <qinputdialog.h>

using namespace std;

void GUI::bindGui()
{
	movieListWidget = new QListWidget();
	playlistWidget = new QListWidget();

	addButton = new QPushButton("Add");
	deleteButton = new QPushButton("Delete");
	updateButton = new QPushButton("Update");
	fileButton = new QPushButton("Open file");
	addToPlaylistButton = new QPushButton("Add to playlist");
	nextButton = new QPushButton("Next");
	playButton = new QPushButton("Play");
	removeFromPlaylistButton = new QPushButton("Remove from playlist");
	nextButton->setStyleSheet(QString("background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 white, stop: 0.4 "
		"gray, stop:1 black)"));

	//text
	titleWidget = new QLineEdit();
	genreWidget = new QLineEdit();
	linkWidget = new QLineEdit();
	yearWidget = new QLineEdit();
	numberLikesWidget = new QLineEdit();
	filterWidget = new QLineEdit();
	selectedMovieWidget = new QLineEdit();

	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QVBoxLayout* leftLayout = new QVBoxLayout(this);
	
	QFormLayout* moviesFormLayout = new QFormLayout();
	moviesFormLayout->addRow("Movies search", filterWidget);
	moviesFormLayout->addWidget(movieListWidget);
	moviesFormLayout->addRow("Title", titleWidget);
	moviesFormLayout->addRow("Genre", genreWidget);
	moviesFormLayout->addRow("Link", linkWidget);
	moviesFormLayout->addRow("Year", yearWidget);
	moviesFormLayout->addRow("Number of likes", numberLikesWidget);

	QGridLayout* gridLayout = new QGridLayout();
	gridLayout->addWidget(addButton, 0, 0); // matrix
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(fileButton, 1, 1);
	gridLayout->addWidget(updateButton, 1, 0);

	leftLayout->addLayout(moviesFormLayout);
	leftLayout->addLayout(gridLayout);

	QVBoxLayout* rightLayout = new QVBoxLayout(this);

	QFormLayout* playlistLayout = new QFormLayout();
	QLabel* l = new QLabel("Playlist");
	l->setAlignment(Qt::AlignCenter);
	playlistLayout->addRow(l);
	playlistLayout->addWidget(playlistWidget);
	playlistLayout->addRow("Selected movie", selectedMovieWidget);
	
	QGridLayout* gridPlaylistLayout = new QGridLayout();
	gridPlaylistLayout->addWidget(addToPlaylistButton, 2, 0); // matrix
	gridPlaylistLayout->addWidget(nextButton, 1, 1);
	gridPlaylistLayout->addWidget(playButton, 1, 0);
	gridPlaylistLayout->addWidget(removeFromPlaylistButton, 2, 1);

	rightLayout->addLayout(playlistLayout);
	rightLayout->addLayout(gridPlaylistLayout);

	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);	
}

void GUI::populate()
{
	movieListWidget->clear();
	playlistWidget->clear();
	vector<Movie> movies = serv.getRepo().getMovies();
	for (Movie& m : movies) {
		movieListWidget->addItem(QString::fromStdString(m.getTitle() + " " + m.getGenre() + " " + m.getTrailer() + " " + std::to_string(m.getYear()) + " " + std::to_string(m.getNumberLikes())));
	}
	movies = serv.getPlaylist()->getMovies();
	for (Movie& m : movies) {
		playlistWidget->addItem(QString::fromStdString(m.getTitle() + " " + m.getGenre() + " " + m.getTrailer() + " " + std::to_string(m.getYear()) + " " + std::to_string(m.getNumberLikes())));
	}
}

void GUI::initFields()
{
	int index = getSelectedIndexMovieList();
	Movie m = serv.getRepo().getMovies()[index];

	titleWidget->setText(QString::fromStdString(m.getTitle()));
	genreWidget->setText(QString::fromStdString(m.getGenre()));
	linkWidget->setText(QString::fromStdString(m.getTrailer()));
	yearWidget->setText(QString::fromStdString(std::to_string(m.getYear())));
	numberLikesWidget->setText(QString::fromStdString(std::to_string(m.getNumberLikes())));
	selectedMovieWidget->setText(QString::fromStdString(m.getTitle() + " " + m.getGenre() + " " + m.getTrailer() + " " + std::to_string(m.getYear()) + " " + std::to_string(m.getNumberLikes())));

}

void GUI::initPlaylistField()
{
	int index = getSelectedIndexPlaylist();
	Movie m = serv.getPlaylist()->getMovies()[index];
	selectedMovieWidget->setText(QString::fromStdString(m.getTitle() + " " + m.getGenre() + " " + m.getTrailer() + " " + std::to_string(m.getYear()) + " " + std::to_string(m.getNumberLikes())));
}

int GUI::getSelectedIndexMovieList()
{
	auto indexes = movieListWidget->selectionModel()->selectedIndexes();
	if (indexes.size() == 0)
		return -1;
	return indexes[0].row();
}

int GUI::getSelectedIndexPlaylist()
{
	auto index = playlistWidget->selectionModel()->selectedIndexes();
	if (index.size() == 0)
		return -1;
	return index[0].row();
}

void GUI::connectSignalsWithSlots()
{
	QObject::connect(removeFromPlaylistButton, &QPushButton::clicked, this, &GUI::removeFromPlaylist);
	QObject::connect(playButton, &QPushButton::clicked, this, &GUI::play);
	QObject::connect(updateButton, &QPushButton::clicked, this, &GUI::update);
	QObject::connect(fileButton, &QPushButton::clicked, this, &GUI::openFile);
	QObject::connect(nextButton, &QPushButton::clicked, this, &GUI::next);
	QObject::connect(filterWidget, &QLineEdit::textChanged, this, &GUI::searchAndFilter);
	QObject::connect(addToPlaylistButton, &QPushButton::clicked, this, &GUI::addToPlaylist);
	QObject::connect(deleteButton, &QPushButton::clicked, this, &GUI::deleteMovie);
	QObject::connect(addButton, &QPushButton::clicked, this, &GUI::addMovie);
	QObject::connect(movieListWidget, &QListWidget::clicked, this, &GUI::initFields);
	QObject::connect(playlistWidget, &QListWidget::clicked, this, &GUI::initPlaylistField);
}

void GUI::deleteMovie()
{
	int index = getSelectedIndexMovieList();
	if (index == -1) {
		QMessageBox::critical(this, QString::fromStdString("Error"), QString::fromStdString("Select something"));
		return;
	}
	Movie m = serv.getRepo().getMovies()[index];
	std::string title = m.getTitle();
	serv.remove(title, m.getYear());
	populate();
}

void GUI::addMovie()
{
	std::string title, genre, trailer;
	int year = yearWidget->text().toInt();
	int numberLikes = numberLikesWidget->text().toInt();

	title = titleWidget->text().toStdString();
	genre = genreWidget->text().toStdString();
	trailer = linkWidget->text().toStdString();

	if (!title.compare("") or !genre.compare("") or !trailer.compare("") or year == 0 or numberLikes == 0)
	{
		QMessageBox::critical(this, QString::fromStdString("Error"), QString::fromStdString("Complete fields with something"));
		return;
	}
	serv.add(title, genre, trailer, year, numberLikes);
	populate();
}

void GUI::addToPlaylist()
{
	int index = getSelectedIndexMovieList();
	if (index == -1) {
		QMessageBox::critical(this, QString::fromStdString("Error"), QString::fromStdString("Select something"));
		return;
	}
	serv.addToPlaylist(serv.getRepo().getMovies()[index]);
	populate();
}

void GUI::removeFromPlaylist()
{
	if (serv.getPlaylist()->getMovies().size() == 0)
	{
		QMessageBox::critical(this, QString::fromStdString("Error"), QString::fromStdString("Playlist is empty"));
		return;
	}
	int index = getSelectedIndexPlaylist();
	if (index == -1) {
		QMessageBox::critical(this, QString::fromStdString("Error"), QString::fromStdString("Select something"));
		return;
	}
	serv.removeFromPlaylist(serv.getPlaylist()->getMovies()[index]);
	selectedMovieWidget->clear();
	populate();
}

void GUI::searchAndFilter()
{
	movieListWidget->clear();
	std::string str = filterWidget->text().toStdString();
	if (str.compare(""))
		populate();
	movieListWidget->clear();
	vector<Movie> movies = serv.getRepo().getMovies();
	for (Movie& m : movies) {
		std::string search = m.getTitle() + m.getGenre() + m.getTrailer() + std::to_string(m.getYear()) + std::to_string(m.getNumberLikes());
		if (search.find(str) != std::string::npos)
			movieListWidget->addItem(QString::fromStdString(m.getTitle() + " " + m.getGenre() + " " + m.getTrailer() + " " + std::to_string(m.getYear()) + " " + std::to_string(m.getNumberLikes())));
	}
}

void GUI::update()
{
	std::string title, genre, trailer;
	int year = yearWidget->text().toInt();
	int numberLikes = numberLikesWidget->text().toInt();

	title = titleWidget->text().toStdString();
	genre = genreWidget->text().toStdString();
	trailer = linkWidget->text().toStdString();

	Movie m = serv.getRepo().findByTitleAndYear(title, year);
	if (m.getGenre() != genre)
		serv.updateMovieString(title, year, genre, 2);
	if (m.getTrailer() != trailer)
		serv.updateMovieString(title, year, trailer, 3);
	if (m.getNumberLikes() != numberLikes)
		serv.updateMovieInteger(title, year, numberLikes, 2);
	populate();
}

void GUI::play()
{
	if (serv.getPlaylist()->getMovies().size() == 0)
	{
		QMessageBox::critical(this, QString::fromStdString("Error"), QString::fromStdString("Playlist is empty"));
		return;
	}
	serv.getPlaylist()->play();
}

void GUI::next()
{
	serv.getPlaylist()->next();
}

void GUI::openFile()
{
	serv.savePlaylist();
	serv.openPlaylist();
}

GUI::GUI(Service& s) : serv{ s } 
{
	bindGui();
	populate();
	connectSignalsWithSlots();
}