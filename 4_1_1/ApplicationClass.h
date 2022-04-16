#ifndef APPLICATIONCLASS_H
#define APPLICATIONCLASS_H

#include "BaseClass.h"

class ApplicationClass :
	public BaseClass
{
public:
	ApplicationClass(BaseClass* parentPtr = nullptr);
	// Построение дерева объектов
	void formTree();
	// Запуск приложения
	int executeApp();
	// Уствновка состояния готовности для объктов
	// Добавлено для КЛ_3_1
	void enterReadiness();
};
#endif
