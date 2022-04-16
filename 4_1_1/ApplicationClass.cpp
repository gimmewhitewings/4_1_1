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
		if (parentName == childName) // Условие выхода
		{
			return;
		}
		// Новый дочерний объект
		BaseClass* child = new BranchClass(childName, ancestor->getObject(parentName));
	}
}

void ApplicationClass::executeApp()
{
	// Вывод имени родительского элемента
	cout << ancestor->childrenList.at(0)->getName();
	// Вызов метода showTree родительского объекта
	ancestor->childrenList.at(0)->printTree();
}