#include <QApplication>
#include <QCommandLineParser>

#include "kdess.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    
    QCoreApplication::setApplicationName("KDESS");
    QCoreApplication::setApplicationVersion("0.1");

    QCommandLineParser parser;  
    parser.setApplicationDescription("KDE Survilance System");
    parser.addHelpOption();
    parser.addVersionOption();
    
    QCommandLineOption iniFileNameOption(QStringList() << "c" << "cfgfile",
            QCoreApplication::translate("main", "configuration file name <iniFileName>."),
            QCoreApplication::translate("main", "iniFileName"));
    parser.addOption(iniFileNameOption);

    parser.process(app);

    const QStringList args = parser.optionNames();
   
    if (args.size() < 1) {
        fprintf(stderr, "%s\n", qPrintable(QCoreApplication::translate("main", "Error: Must specify an argument.")));
        parser.showHelp(1);
    }
    
    const QString option = args.isEmpty() ? QString() : args.first();
    
    if(!(option == "cfgfile" || option == "c")) {
        fprintf(stderr, "%s\n", qPrintable(QCoreApplication::translate("main", "Error: Unknown argument.")));
        parser.showHelp(1);
    }
       
    KDESS kdess(parser.value(iniFileNameOption));
    kdess.showFullScreen();
    return app.exec();
}
