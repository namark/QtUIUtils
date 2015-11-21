#include "checkvisibilitygroup.h"

using namespace QtUIUtils;

bool CheckVisibilityGroup::abilityCheck(bool enabled)
{
    return true;
}

bool CheckVisibilityGroup::visibilityCheck(bool visible)
{
    return visible;
}

CheckVisibilityGroup::CheckVisibilityGroup(QAbstractButton* check, bool invert,  QObject *parent) :
    CheckGroup(check, invert, parent)
{
//    check->setChecked(false);
}

