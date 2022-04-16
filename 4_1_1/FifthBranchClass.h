#ifndef FIFTHBRANCH_H
#define FIFTHBRANCH_H

#include "BaseClass.h"
class FifthBranchClass :
    public BaseClass
{
public:
    FifthBranchClass(string objectName, BaseClass* root) :
        BaseClass(objectName, root) {};
};

#endif
