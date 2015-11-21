#include "checkgroup.h"

using namespace QtUIUtils;

void CheckGroup::enableWidgets(bool enabled)
{
    for(int i=0, l=_widgets.length(); i<l; ++i)
        _widgets[i]->setEnabled(enabled);
}

void CheckGroup::setWigetsVisibility(bool visible)
{
    for(int i=0, l=_widgets.length(); i<l; ++i)
        _widgets[i]->setVisible(visible);
}

CheckGroup::CheckGroup(QAbstractButton *check, bool invert, QObject *parent)
    :QObject(parent), _check(check), _invert(invert)
{
    connect(_check, SIGNAL(toggled(bool)), this, SLOT(checked(bool)));
}

void CheckGroup::add(QWidget *widget)
{
    _widgets << widget;
}

void CheckGroup::enable(bool enabled)
{
    _check->setEnabled(enabled);
    enableWidgets(enabled && abilityCheck(_check->isChecked() ^ _invert));
}

void CheckGroup::disable(bool disabled)
{
    enable(!disabled);
}

void CheckGroup::visible(bool visible)
{
    _check->setVisible(visible);
    setWigetsVisibility(visible  && visibilityCheck(_check->isChecked() ^ _invert));
}

void CheckGroup::checked(bool checked)
{
    checked = checked ^ _invert;
    enableWidgets(abilityCheck(checked));
    setWigetsVisibility(visibilityCheck(checked));
}
