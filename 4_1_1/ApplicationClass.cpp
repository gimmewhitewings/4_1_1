#include "ApplicationClass.h"

ApplicationClass::ApplicationClass(BaseClass* parentPtr)
{
	BaseClass::ancestor->setParent(parentPtr);
	BaseClass::ancestor->setName("ancestor");
}

void ApplicationClass::formTree()
{
	string parentName, childName;

	cin >> parentName;
	cin.clear();
	cin.ignore(1024, '\n');

	BaseClass* head = new BaseClass(parentName);
	while (true)
	{
		cin >> parentName >> childName;
		if (parentName == childName)
		{
			return;
		}

		BaseClass* child = new BaseClass(childName, ancestor->getObject(parentName));
	}
}

void ApplicationClass::executeApp()
{
	cout << ancestor->childrenList.at(0)->getName();
	ancestor->childrenList.at(0)->printTree();
}