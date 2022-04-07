#ifndef BASECLASS_H
#define BASECLASS_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class BaseClass
{
private:
	string objectName = "";
	BaseClass* parentPtr = nullptr; // Указатель на родительский объект
public:
	static BaseClass* ancestor; //Корневой объект по умолчанию
	vector<BaseClass*> childrenList; // Список производных элементов

	BaseClass() : parentPtr{ nullptr } {} // Конструктор по умолчанию
	BaseClass(string objectName, BaseClass* parentPtr = nullptr); //Параметризованный конструктор

	void setName(string objectName) { this->objectName = objectName; }
	string getName() { return objectName; }
	void setParent(BaseClass* parentPtr) { this->parentPtr = parentPtr; }
	BaseClass* getObject(string objectName);
	void printTree();
};
#endif
