/**
 * \file main.h
 * Entry point for the GUI executable
 * 
 * \author Igor Siemienowicz
 * 
 * \copyright Copyright Igor Siemienowicz 2018 Distributed under the Boost
 * Software License, Version 1.0. (See accompanying file ../LICENSE_1_0.txt
 * or copy at https://www.boost.org/LICENSE_1_0.txt
 */

#include <QApplication>
#include <QDebug>

#include <qlib/qlib.h>

#include "mainwindow.h"

/**
 * \brief Entry point for the GUI executable
 * 
 * This function instantiates the main window and application classes, shows
 * the window, and starts the application loop
 * 
 * \param argc The number of command-line arguments
 * 
 * \param argv The array of command-line argument
 * 
 * \return The return code from `QApplication::exec` (non-zero on error)
 */
int main(int argc, char *argv[])
{

    // Set up the logger to send messages to the Qt output streams
    //
    // TODO abstract this out into a separate function, that also takes
    // program options into account.
    qlib::logger::instance().add(
        { qlib::logger::level_t::error }
        , [](qlib::logger::level_t, const std::wstring& msg)
            {
                qCritical() << qPrintable(QString::fromStdWString(msg));
            });

    qlib::logger::instance().add(
        { qlib::logger::level_t::warning }
        , [](qlib::logger::level_t, const std::wstring& msg)
            {
                qWarning() << qPrintable(QString::fromStdWString(msg));
            });

    qlib::logger::instance().add(
        { qlib::logger::level_t::info }
        , [](qlib::logger::level_t, const std::wstring& msg)
            {
                qInfo() << qPrintable(QString::fromStdWString(msg));
            });

    qlib::logger::instance().add(
        { qlib::logger::level_t::debug }
        , [](qlib::logger::level_t, const std::wstring& msg)
            {
                qDebug() << qPrintable(QString::fromStdWString(msg));
            });

    qlib::logger::instance().log(
        qlib::logger::level_t::info
        , L"application starting");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

}   // end main function
