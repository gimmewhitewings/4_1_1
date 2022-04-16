#ifndef APPLICATIONCLASS_H
#define APPLICATIONCLASS_H
#include "BaseClass.h"
#include "BranchClass.h"

class ApplicationClass :
	public BaseClass
{
public:
	ApplicationClass(BaseClass* parentPtr = nullptr);
	void formTree();
	void executeApp();
};
#endif
