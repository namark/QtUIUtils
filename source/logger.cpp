#include "logger.h"

using namespace QtUIUtils;

void Logger::lockContent()
{
    if(!_auto_update)  _content_mutex.lock();
}

void Logger::unlockContent()
{
    if(!_auto_update) _content_mutex.unlock();
}

Logger::Logger() : _auto_update(true), _toggle{0}, _output(0), _vg(0)
{
}

Logger::Logger(QTextBrowser *output, QAbstractButton *toggle, QObject *parent)
    : QObject(parent), _auto_update(true), _toggle(toggle), _output(output)
{
    _vg = new CheckVisibilityGroup(_toggle, false, this);
    _vg->add(_output);
}

void Logger::set(QTextBrowser *output, QAbstractButton *toggle)
{
    _toggle = toggle;
    _output = output;
//    delete _vg;
    _vg = new CheckVisibilityGroup(_toggle, false, this);
    _vg->add(_output);

}

Logger &Logger::operator<<(const QString &message)
{
    lockContent();
    _content += message + "<br />" ;
    _plain_content += message + "\n";
    unlockContent();
    if(_auto_update) update();
    return *this;
}

Logger &Logger::operator!=(const QString &message)
{
    lockContent();
    _content += "<span style='color:red; font-weight:bold;'> ERROR: " + message + "</span><br />";
    _plain_content += "ERROR: " + message + "\n";
    unlockContent();
    if(_auto_update) update();
    return *this;
}

void Logger::update()
{
    lockContent();
    _output->setHtml(_content);
    unlockContent();
}

void Logger::clear()
{
    lockContent();
    _content.clear();
    _plain_content.clear();
    unlockContent();
}

void Logger::autoUpdate(bool auto_update)
{
    _auto_update = auto_update;
}
