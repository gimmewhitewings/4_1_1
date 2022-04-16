#ifndef THIRDBRANCH_H
#define THIRDBRANCH_H

#include "BaseClass.h"
class ThirdBranchClass :
    public BaseClass
{
public:
    ThirdBranchClass(string objectName, BaseClass* root) :
        BaseClass(objectName, root) {};
};

#endif
