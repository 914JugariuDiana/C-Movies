#include "QtWidgetsApplication.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "File.h"
#include "Html.h"
#include "Service.h"
#include "CSV.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QtWidgetsApplication w;
    //w.show();
	Repository repo{ "Movies.txt" };
	File* p;
	/*switch (option)
	{
	case 1:
		p = new CSV{};
		break;
	case 2:
		p = new Html{};
		break;
	default:
		std::cout << "Not available";
		return 0;
	}*/
	p = new CSV{};
	Service serv{ repo, p };
	GUI gui(serv);
	gui.show();
	return a.exec();
}
