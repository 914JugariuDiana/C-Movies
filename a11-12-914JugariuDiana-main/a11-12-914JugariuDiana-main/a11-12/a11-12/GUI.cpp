#include "GUI.h"
#include <qvboxlayout>
#include <qformlayout.h>

void GUI::bindGui()
{
	movieListWidget = new QListWidget();
	addButton = new QPushButton("Add");
	deleteButton = new QPushButton("Delete");
	titleWidget = new QLineEdit();
	genreWidget = new QLineEdit();
	linkWidget = new QLineEdit();
	yearWidget = new QLineEdit();
	numberLikesWidget = new QLineEdit();

	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addWidget(movieListWidget);
	QFormLayout* formLayout = new QFormLayout();
	formLayout->addRow("Title", titleWidget);
	formLayout->addRow("Genre", genreWidget);
	formLayout->addRow("Link", linkWidget);
	formLayout->addRow("Year", yearWidget);
	formLayout->addRow("Number of likes", numberLikesWidget);
	mainLayout->addLayout(formLayout);
	//QGridLayout* gridLayout = new QGridLayout();

}


GUI::GUI(Service& s) : serv{ s } {}