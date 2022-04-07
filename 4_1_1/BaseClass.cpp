#include "BaseClass.h"

BaseClass* BaseClass::ancestor = new BaseClass();

BaseClass::BaseClass(string objectName, BaseClass* parentPtr) : objectName{ objectName }
{
	if (parentPtr)
	{
		setParent(parentPtr);
		parentPtr->childrenList.push_back(this);
	}
	else
	{
		setParent(ancestor);
		ancestor->childrenList.push_back(this);
	}
}

BaseClass* BaseClass::getObject(string objectName)
{
	// Проход по всем производным элементам данного объекта
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		if (childrenList.at(i)->getName() == objectName)
		{
			return childrenList.at(i);
		}
	}

	// Если не нашлось нужного элемента, идём в глубь дерева, применяя метод к крайнему правому дочернему элементу
	if (!childrenList.empty())
	{
		return childrenList.back()->getObject(objectName);
	}
	else // Если у элемента нет производных, возвращаем его самого
	{
		return this;
	}
}

void BaseClass::printTree()
{
	cout << endl << getName() << "  ";
	// Проход по дочерним элементам текущего объекта
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		cout << childrenList.at(i)->getName();
		// Если элемент не последний производный объект
		if (i + 1 < childrenList.size())
		{
			cout << "  ";
		}
	}

	// Проход по всем дочерним элементам с использованием рекурсии
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		// Проверка наличия хотя бы одного дочернего элемента
		if (!childrenList.at(i)->childrenList.empty())
		{
			// Вызов метода printTree для каждого дочернего элемента
			childrenList.at(i)->printTree();
		}
	}
}