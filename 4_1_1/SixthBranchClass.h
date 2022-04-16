#ifndef SIXTHRANCH_H
#define SIXTHRANCH_H

#include "BaseClass.h"
class SixthBranchClass :
    public BaseClass
{
public:
    SixthBranchClass(string objectName, BaseClass* root) :
        BaseClass(objectName, root) {};
};

#endif
