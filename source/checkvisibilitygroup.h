#ifndef CHECKVISIBILITYGROUP_H
#define CHECKVISIBILITYGROUP_H

#include "checkgroup.h"

namespace QtUIUtils
{

class CheckVisibilityGroup : public CheckGroup
{
    Q_OBJECT

    bool abilityCheck(bool enabled);
    bool visibilityCheck(bool visible);
public:
    CheckVisibilityGroup(QAbstractButton* check, bool invert = false, QObject *parent = 0);

signals:

public slots:

};

}
#endif // CHECKVISIBILITYGROUP_H
