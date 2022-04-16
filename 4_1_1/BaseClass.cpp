#include "BaseClass.h"

BaseClass* BaseClass::ancestor = new BaseClass(); // �������� ��������� ��������

BaseClass::BaseClass(string objectName, BaseClass* parentPtr) : objectName{ objectName }
{
	if (parentPtr) // ���� ������ �� ��������
	{
		setParent(parentPtr);
	}
	else
	{
		setParent(ancestor);
	}
}

// ������������ � ������ formTree ������ ApplicationClass
// ��������� ������� �� ��� �����
BaseClass* BaseClass::getObject(string objectName)
{
	// ������ �� ���� ����������� ��������� ������� �������
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		if (childrenList.at(i)->getName() == objectName)
		{
			return childrenList.at(i);
		}
	}

	// ���� �� ������� ������� ��������, ����������� ������ ������,
	// ������� ������ ����� � �������� ��������� ��������
	if (!childrenList.empty())
	{
		return childrenList.back()->getObject(objectName);
	}
	else // ���� � �������� ��� �����������, ���������� ��� ������
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

	// ������� ������ �� ��������
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
	// �������� ������ � ��� ������, ���� ��������� � ��������� �� null
	// �.�. ���� ������ ������ �� � ��������� �������
	if (parentPtr)
	{
		const size_t size = parentPtr->childrenList.size();
		/* ���� �������� �� ������ �������� ��������� � ������� �� ���� �������,
		* ������� �������� ����������� */
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
