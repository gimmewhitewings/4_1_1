#ifndef FOURTHBRANCH_H
#define FOURTHBRANCH_H

#include "BaseClass.h"
class FourthBranchClass :
    public BaseClass
{
public:
    FourthBranchClass(string objectName, BaseClass* root) :
        BaseClass(objectName, root) {};
};

#endif