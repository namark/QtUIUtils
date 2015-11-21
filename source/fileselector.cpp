#include "fileselector.h"

using namespace QtUIUtils;

FileSelector::FileSelector(QWidget* parent,
                           QListWidget *list, QAbstractButton *add, QAbstractButton *remove,
                           const QString& dialog_caption, const QString& filetypes)
    :QObject(parent), parent(parent), list(list), btn_add(add), btn_remove(remove),
     dialog_caption(dialog_caption), filetypes(filetypes)
{
    connect(add,SIGNAL(clicked()), this, SLOT(selectAndAddFiles()));
    connect(remove, SIGNAL(clicked()), this, SLOT(removeSelected()));
}

const QList<FileName>& FileSelector::getFilenames() const
{
    return filenames;
}

void FileSelector::enable(bool enabled) const
{
    btn_add->setEnabled(enabled);
    btn_remove->setEnabled(enabled);
}

void FileSelector::disable(bool disabled) const
{
    btn_add->setDisabled(disabled);
    btn_remove->setDisabled(disabled);
}

void FileSelector::setEnabled(bool enabled)
{
    enable(enabled);
    list->setEnabled(enabled);
}

void FileSelector::setDisabled(bool disabled)
{
    disable(disabled);
    list->setDisabled(disabled);
}

void FileSelector::setDir(const QString &dir)
{
    last_dir = dir;
}

void FileSelector::selectAndAddFiles()
{
    add(QFileDialog::getOpenFileNames(parent, dialog_caption, last_dir, filetypes));
}

void FileSelector::removeSelected()
{
    QStringList signalData;
    const QList<QListWidgetItem*>&& selected = list->selectedItems();
    for(int i = selected.count()-1; i>=0; --i)
    {
        signalData << filenames[i];
        filenames.removeAt(i);
        delete selected[i];
    }
    emit removed(signalData);
}

void FileSelector::add(const QStringList &names)
{
    QStringList signalData;
    for(int i = 0, l = names.length(); i < l; ++i)
    {
        if(!filenames.contains(names[i]))
        {
            filenames << names[i];
            signalData << names[i];
            list->addItem(createListWidgetItem(filenames.last()));
        }
    }
    emit added(signalData);
}

QListWidgetItem* FileSelector::createListWidgetItem(const FileName& filename)
{
    return new QListWidgetItem(filename.name());
//    return new QListWidgetItem(QIcon(QPixmap(filename)), filename.name());
}

void FileSelector::set(const QStringList &names)
{
    list->selectAll();
    removeSelected();
    add(names);
}


