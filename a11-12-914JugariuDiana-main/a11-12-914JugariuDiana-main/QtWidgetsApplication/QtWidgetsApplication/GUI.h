#pragma once
#include <QWidget.h>
#include "Service.h"
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlabel.h>

class GUI : public QWidget
{
private:
	Service& serv;

	QListWidget* movieListWidget;
	QListWidget* playlistWidget;
	QPushButton* playButton;
	QPushButton* fileButton;
	QPushButton* nextButton;
	QPushButton* addToPlaylistButton;
	QPushButton* removeFromPlaylistButton;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QLineEdit* titleWidget, *genreWidget, *linkWidget, *yearWidget, *numberLikesWidget, *filterWidget, *selectedMovieWidget, *textLine;
	void bindGui();
	void populate();
	void initFields();
	void initPlaylistField();
	int getSelectedIndexMovieList();
	int getSelectedIndexPlaylist();
	void connectSignalsWithSlots();
	void deleteMovie();
	void addMovie();
	void addToPlaylist();
	void removeFromPlaylist();
	void searchAndFilter();
	void update();
	void play();
	void next();
	void openFile();
public:
	GUI(Service& s);

};