#include "BaseClass.h"

BaseClass* BaseClass::ancestor = new BaseClass(); // Создание корневого элемента

BaseClass::BaseClass(string objectName, BaseClass* parentPtr) : objectName{ objectName }
{
	if (parentPtr) // Если объект не корневой
	{
		setParent(parentPtr);
	}
	else
	{
		setParent(ancestor);
	}
}

// Используется в методе formTree класса ApplicationClass
// Получение объекта по его имени
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

	// Если не нашлось нужного элемента, погружаемся вглубь дерева,
	// вызывая данный метод к крайнему дочернему элементу
	if (!childrenList.empty())
	{
		return childrenList.back()->getObject(objectName);
	}
	else // Если у элемента нет производных, возвращаем его самого
	{
		return this;
	}
}

void BaseClass::printTree(bool isPrintReadiness, unsigned tableLevel)
{
	string tabsLength;
	tabsLength.append(4 * tableLevel,' ');
	cout << '\n' << tabsLength << this->getName();

	if (isPrintReadiness)
	{
		if (this->getReadiness())
		{
			cout << " is redy";
		}
		else
		{
			cout << " is not ready";
		}
	}

	// Условие выхода из рекурсии
	if (childrenList.empty())
	{
		return;
	}

	for (size_t i = 0; i < childrenList.size(); i++)
	{
		childrenList.at(i)->printTree(isPrintReadiness, tableLevel + 1);
	}
}

void BaseClass::setReadiness(int numericReadiness)
{
	if (numericReadiness)
	{
		BaseClass* tempParentPtr = this->parentPtr;
		while (tempParentPtr)
		{
			if (!(tempParentPtr->getReadiness()))
			{
				return;
			}
			tempParentPtr = tempParentPtr->getParent();
		}
		this->readiness = true;
	}
	return;
}

void BaseClass::setParent(BaseClass* parentPtr)
{
	// Действие только в том случае, если указатель н ародителя не null
	// т.е. если методо вызван не к корневому объекту
	if (parentPtr)
	{
		const size_t size = parentPtr->childrenList.size();
		/* Цикл проходит по списку дочерних элементов и удаляет из него элемент,
		* который перестал подчиняться */
		for (size_t i = 0; i < size; i++)
		{
			if (parentPtr->childrenList.at(i) == this)
			{
				parentPtr->childrenList.erase(parentPtr->childrenList.begin() + i);
				break;
			}
		}
		parentPtr->childrenList.push_back(this);
	}
	this->parentPtr = parentPtr;
}
