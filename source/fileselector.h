#ifndef FILESELECTOR_H
#define FILESELECTOR_H

#include "filename.h"
#include <QListWidget>
#include <QPushButton>
#include <QStringList>
#include <QList>
#include <QFileDialog>

namespace QtUIUtils
{

class FileSelector : public QObject
{
    Q_OBJECT

    QWidget* parent;
    QListWidget *list;
    QAbstractButton *btn_add, *btn_remove;
    QString dialog_caption;
    QString filetypes;
    QList<FileName> filenames;
    QString last_dir;

    FileSelector(){}
public:
    FileSelector(QWidget* parent,
                 QListWidget *list, QAbstractButton *add, QAbstractButton *remove,
                 const QString& dialog_title = QString(), const QString& filetypes = QString());

    const QList<FileName> &getFilenames() const;
    // logical enable/disable, ignores the listWidget
    void enable(bool enabled = true) const;
    void disable(bool disabled = true) const;
    // traditional enable/disable, all elements...
    void setEnabled(bool enabled = true);
    void setDisabled(bool disabled = true);

    void setDir(const QString& dir = QString());

private slots:
public slots:
    void selectAndAddFiles();
    void removeSelected();
    void add(const QStringList &names);
    void set(const QStringList &names);
signals:
    void added(const QStringList &filenames);
    void removed(const QStringList &filenames);
protected:
    QListWidgetItem* createListWidgetItem(const FileName &filename);
};

}

#endif // FILESELECTOR_H
