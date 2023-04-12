#include "QtWidgetsApplication.h"
#include <QtWidgets/QApplication>
#include "GUI.h"
#include "CSV.h"
#include "File.h"
#include "Service.h"
#include "Repository.h"
#include "Html.h"
#include <qmessagebox.h>
#include <qmainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	Repository repo{ "Movies.txt" };
	QMessageBox msgBox;
	msgBox.setInformativeText("Do you want to work with html or csv <yes for html>?");
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	int ret = msgBox.exec();
	File* p;
	switch (ret) {
	case QMessageBox::Yes:
		p = new Html{};
		break;
	case QMessageBox::No:
		p = new CSV{};
		break;
	default:
		return 0;
	}
	
	Service serv{ repo, p };
	GUI gui(serv);
	gui.show();
    return a.exec();
}
