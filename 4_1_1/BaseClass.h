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
	bool readiness = false; // Добавлено в КП_3_1. Готовность объекта
public:
	static BaseClass* ancestor; //Корневой объект по умолчанию
	vector<BaseClass*> childrenList; // Список производных элементов

	BaseClass() : parentPtr{ nullptr } {} // Конструктор по умолчанию
	BaseClass(string objectName, BaseClass* parentPtr = nullptr); //Параметризованный конструктор

	// Сеттеры
	void setName(string objectName) { this->objectName = objectName; }
	void setParent(BaseClass* parentPtr);
	void setReadiness(int numericReadiness);
	// Геттеры
	string getName() { return objectName; }
	BaseClass* getParent() { return parentPtr; }
	BaseClass* getObject(string objectName);
	bool getReadiness() { return readiness; }

	void printTree(bool isPrintReadiness, unsigned tableLevel = 0);
};
#endif
