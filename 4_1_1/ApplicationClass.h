#pragma once
#include "BaseClass.h"
class ApplicationClass :
	public BaseClass
{
public:
	ApplicationClass(BaseClass* parentPtr = nullptr);
	void formTree();
	void executeApp();
};

