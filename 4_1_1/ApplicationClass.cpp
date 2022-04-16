#include "ApplicationClass.h"
#include "BranchClass.h"
#include "SecondBranchClass.h"
#include "ThirdBranchClass.h"
#include "FourthBranchClass.h"
#include "FifthBranchClass.h"
#include "SixthBranchClass.h"

ApplicationClass::ApplicationClass(BaseClass* parentPtr)
{
	BaseClass::ancestor->setParent(parentPtr);
	BaseClass::ancestor->setName("ancestor");
	BaseClass::ancestor->setReadiness(1);
}

// Изменено для КЛ_3_1
void ApplicationClass::formTree()
{
	string parentName, childName;
	int classNumber;

	cin >> parentName;
	// Головной объект
	BaseClass* head = new BaseClass(parentName);
	cin >> parentName;
	while (parentName != "endtree")
	{
		cin >> childName >> classNumber;
		// Определение номера класса
		switch (classNumber)
		{
		case 2:
		{
			BaseClass* child = new SecondBranchClass(childName, ancestor->getObject(parentName));
			break;
		}
		case 3:
		{
			BaseClass* child = new ThirdBranchClass(childName, ancestor->getObject(parentName));
			break;
		}
		case 4:
		{
			BaseClass* child = new FourthBranchClass(childName, ancestor->getObject(parentName));
			break;
		}
		case 5:
		{
			BaseClass* child = new FifthBranchClass(childName, ancestor->getObject(parentName));
			break;
		}
		case 6:
		{
			BaseClass* child = new SixthBranchClass(childName, ancestor->getObject(parentName));
			break;
		}
		default:
			break;
		}
		cin >> parentName;
	}
}

int ApplicationClass::executeApp() // Выполнение основного алгоритма программы
{
	cout << "Object tree";
	ancestor->childrenList.front()->printTree(false); // Вывод дерева без готовностей
	cout << "\nThe tree of objects and their radiness";
	ancestor->childrenList.front()->printTree(true); // Вывод дерева с готовностями
	return 0;
}

void ApplicationClass::enterReadiness() // Установка готовности объекта
{
	string objectName;
	int numericReadiness;
	while (cin >> objectName >> numericReadiness)
	{
		ancestor->getObject(objectName)->setReadiness(numericReadiness);
	}
}