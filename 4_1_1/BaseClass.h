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
	BaseClass* parentPtr = nullptr; // ��������� �� ������������ ������
public:
	static BaseClass* ancestor; //�������� ������ �� ���������
	vector<BaseClass*> childrenList; // ������ ����������� ���������

	BaseClass() : parentPtr{ nullptr } {} // ����������� �� ���������
	BaseClass(string objectName, BaseClass* parentPtr = nullptr); //����������������� �����������

	void setName(string objectName) { this->objectName = objectName; }
	string getName() { return objectName; }
	void setParent(BaseClass* parentPtr) { this->parentPtr = parentPtr; }
	BaseClass* getObject(string objectName);
	void printTree();
};
#endif
