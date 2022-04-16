#ifndef SECONDBRANCH_H
#define SECONDBRANCH_H

#include "BaseClass.h"
class SecondBranchClass :
    public BaseClass
{
public:
	SecondBranchClass(string objectName, BaseClass* root) :
		BaseClass(objectName, root) {};
};

#endif
