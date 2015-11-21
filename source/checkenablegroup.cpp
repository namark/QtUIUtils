#include "checkenablegroup.h"

using namespace QtUIUtils;

CheckEnableGroup::CheckEnableGroup(QAbstractButton *check, bool invert, QObject *parent)
    : CheckGroup(check, invert, parent)
{
//    check->setChecked(false);
}

bool CheckEnableGroup::abilityCheck(bool enabled)
{
    return enabled;
}

bool CheckEnableGroup::visibilityCheck(bool visible)
{
    return true;
}
