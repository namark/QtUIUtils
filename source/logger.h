#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include "checkvisibilitygroup.h"
#include <QTextBrowser>
#include <mutex>

namespace QtUIUtils
{

class Logger : public QObject
{
    Q_OBJECT

    QString _plain_content; // TODO: use or remove
    QString _content;
    std::mutex _content_mutex;
    bool _auto_update;

    QAbstractButton* _toggle;
    QTextBrowser* _output;

    CheckVisibilityGroup * _vg;

    void lockContent();
    void unlockContent();

public:
    Logger();
    Logger(QTextBrowser* output, QAbstractButton* toggle = 0, QObject *parent = 0);

    void set(QTextBrowser* output, QAbstractButton* toggle = 0);

    Logger& operator<<(const QString& message); // const LoggerMessage& message
    Logger& operator!=(const QString& message);

    void update();
    void clear();

    void autoUpdate(bool auto_update);

signals:

public slots:

};

}

#endif // LOGGER_H
