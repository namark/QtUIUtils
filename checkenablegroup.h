#ifndef CHECKENABLEGROUP_H
#define CHECKENABLEGROUP_H

#include "checkgroup.h"

namespace QtUIUtils
{

class CheckEnableGroup : public CheckGroup
{
    Q_OBJECT

    //CheckEnableGroup(){}
    bool abilityCheck(bool enabled);
    bool visibilityCheck(bool visible);
public:
    CheckEnableGroup(QAbstractButton* check, bool invert = false, QObject * parent = 0);


};

}
#endif // CHECKENABLEGROUP_H
