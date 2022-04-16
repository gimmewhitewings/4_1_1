#ifndef BRANCHCLASS_H
#define BRANCHCLASS_H
#include "BaseClass.h"
class BranchClass :
	public BaseClass
{
public:
	BranchClass(string objectName, BaseClass* root) :
		BaseClass(objectName, root) {};
};
#endif