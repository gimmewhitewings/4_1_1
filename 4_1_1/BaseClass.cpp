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
	// ������ �� ���� ����������� ��������� ������� �������
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		if (childrenList.at(i)->getName() == objectName)
		{
			return childrenList.at(i);
		}
	}

	// ���� �� ������� ������� ��������, ��� � ����� ������, �������� ����� � �������� ������� ��������� ��������
	if (!childrenList.empty())
	{
		return childrenList.back()->getObject(objectName);
	}
	else // ���� � �������� ��� �����������, ���������� ��� ������
	{
		return this;
	}
}

void BaseClass::printTree()
{
	cout << endl << getName() << "  ";
	// ������ �� �������� ��������� �������� �������
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		cout << childrenList.at(i)->getName();
		// ���� ������� �� ��������� ����������� ������
		if (i + 1 < childrenList.size())
		{
			cout << "  ";
		}
	}

	// ������ �� ���� �������� ��������� � �������������� ��������
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		// �������� ������� ���� �� ������ ��������� ��������
		if (!childrenList.at(i)->childrenList.empty())
		{
			// ����� ������ printTree ��� ������� ��������� ��������
			childrenList.at(i)->printTree();
		}
	}
}