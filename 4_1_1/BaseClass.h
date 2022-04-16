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
	bool readiness; // ��������� � ��_3_1. ���������� �������
public:
	static BaseClass* ancestor; //�������� ������ �� ���������
	vector<BaseClass*> childrenList; // ������ ����������� ���������

	BaseClass() : parentPtr{ nullptr } {} // ����������� �� ���������
	BaseClass(string objectName, BaseClass* parentPtr = nullptr); //����������������� �����������

	void setName(string objectName) { this->objectName = objectName; }
	string getName() { return objectName; }
	void setParent(BaseClass* parentPtr);
	BaseClass* getParent() { return parentPtr; }
	BaseClass* getObject(string objectName);
	void printTree();
	bool getReadiness() { return readiness; }
	void setReadiness(int numericReadiness);
};
#endif
