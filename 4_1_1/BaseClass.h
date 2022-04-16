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
	bool readiness = false; // ��������� � ��_3_1. ���������� �������
public:
	static BaseClass* ancestor; //�������� ������ �� ���������
	vector<BaseClass*> childrenList; // ������ ����������� ���������

	BaseClass() : parentPtr{ nullptr } {} // ����������� �� ���������
	BaseClass(string objectName, BaseClass* parentPtr = nullptr); //����������������� �����������

	// �������
	void setName(string objectName) { this->objectName = objectName; }
	void setParent(BaseClass* parentPtr);
	void setReadiness(int numericReadiness);
	// �������
	string getName() { return objectName; }
	BaseClass* getParent() { return parentPtr; }
	BaseClass* getObject(string objectName);
	bool getReadiness() { return readiness; }

	void printTree(bool isPrintReadiness, unsigned tableLevel = 0);
};
#endif
