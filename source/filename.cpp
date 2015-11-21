#include "filename.h"

using namespace QtUIUtils;

void FileName::init()
{
    setDirectorySeparators("/\\");
    _detected_separator = 0;
}

FileName::FileName()
{
    init();
}

FileName::FileName(const QString &full_name)
{
    init();
    setFullName(full_name);
}

void FileName::setFullName(const QString &full_name)
{
    int sep;
    QString notype_name;
    for(sep = full_name.length()-1; sep >=0; --sep)
    {
        _detected_separator = full_name.at(sep);
        if(_detected_separator == '.') // TODO: get rid of this magic character
        {
            notype_name = full_name.left(sep);
            _type = full_name.mid(sep);
        }
        if(_directory_separators.contains(_detected_separator))
        {
            ++sep;
            _path = notype_name.left(sep);
            _name = notype_name.mid(sep);
            return;
        }
    }
    _detected_separator = 0;
}

QString FileName::fullName() const
{
    return _path + _name + _type;
}

const QString &FileName::type() const
{
    return _type;
}

const QString &FileName::name() const
{
    return _name;
}

const QString &FileName::path() const
{
    return _path;
}

void FileName::setType(const QString &type)
{
    _type = type;
}

void FileName::setName(const QString &name)
{
    _name = name;
}

void FileName::setPath(const QString &path)
{
    _path = path;
}

FileName &FileName::operator=(const char *str)
{
    setFullName(str);
    return *this;
}

FileName &FileName::operator=(const QString &str)
{
    setFullName(str);
    return *this;
}

FileName::operator QString() const
{
    return fullName();
}

FileName::operator char *() const
{
    return fullName().toLatin1().data();
}

void FileName::setDirectorySeparators(const QString &separators)
{
    _directory_separators.clear();
    for(int i = 0, l = separators.length(); i < l; ++i)
    _directory_separators << separators.at(i);
}

void FileName::addDirectorySeparators(const QString &separators)
{
    for(int i = 0, l = separators.length(); i < l; ++i)
    _directory_separators << separators.at(i);
}

const QList<QChar> &FileName::directorySeparators() const
{
    return _directory_separators;
}

bool FileName::operator==(const FileName &filename) const
{
    return _path == filename._path && _name == filename._name && _type == filename._type;
}

QChar FileName::detected_separator()
{
    return _detected_separator;
}
