#ifndef APPLICATIONCLASS_H
#define APPLICATIONCLASS_H

#include "BaseClass.h"

class ApplicationClass :
	public BaseClass
{
public:
	ApplicationClass(BaseClass* parentPtr = nullptr);
	// ���������� ������ ��������
	void formTree();
	// ������ ����������
	int executeApp();
	// ��������� ��������� ���������� ��� �������
	// ��������� ��� ��_3_1
	void enterReadiness();
};
#endif
