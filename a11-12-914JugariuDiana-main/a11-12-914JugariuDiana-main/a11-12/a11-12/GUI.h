#pragma once
#include "QWidget.h"
#include "Service.h"
#include "qlistwidget.h"
#include "qpushbutton.h"
#include "qlineedit.h"

class GUI : public QWidget
{
private:
	Service& serv;
	QListWidget* movieListWidget;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateLinkButton;
	QPushButton* updateGenreButton;
	QLineEdit* titleWidget, *genreWidget, *linkWidget, *yearWidget, *numberLikesWidget;
	void bindGui();
public:
	GUI(Service& s);

};