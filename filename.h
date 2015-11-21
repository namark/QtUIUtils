#ifndef FILENAME_H
#define FILENAME_H
#include <QString>
#include <QList>

namespace QtUIUtils
{

class FileName
{
    QList<QChar> _directory_separators;
    QChar _detected_separator;

    QString _type;
    QString _name;
    QString _path;

    void init();

public:
    FileName();
    FileName(const QString& full_name);

    void setFullName(const QString& full_name);
    QString fullName() const;

    const QString& type() const;
    const QString& name() const;
    const QString& path() const;
    void setType(const QString& type);
    void setName(const QString& name);
    void setPath(const QString& path);

    operator char*() const;
    operator QString() const;

    FileName& operator=(const char* str);
    FileName& operator=(const QString& str);

    void setDirectorySeparators(const QString& separators);
    void addDirectorySeparators(const QString& separators);
    const QList<QChar>&  directorySeparators() const;

    bool operator==(const FileName& filename) const;
    QChar detected_separator();
};

}
#endif // FILENAME_H
