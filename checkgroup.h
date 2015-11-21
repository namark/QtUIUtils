#ifndef CHECKGROUP_H
#define CHECKGROUP_H

#include <QObject>
#include <QWidget>
#include <QAbstractButton>

namespace QtUIUtils
{

class CheckGroup : public QObject
{
    Q_OBJECT

    QAbstractButton *_check;
    QList<QWidget*> _widgets;

    bool _invert;

    CheckGroup(){}

    void enableWidgets(bool enabled = true);
    void setWigetsVisibility(bool visible = true);

    virtual bool abilityCheck(bool enabled) = 0;
    virtual bool visibilityCheck(bool visible) = 0;
public:
    CheckGroup(QAbstractButton* check, bool invert = false, QObject * parent = 0);
    void add(QWidget *widget);

    void enable(bool enabled = true);
    void disable(bool disabled = true);
    void visible(bool visible = true);
private slots:
    void checked(bool checked);

};

}

#endif // CHECKGROUP_H
