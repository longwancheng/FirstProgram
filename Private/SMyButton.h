
#pragma once
#include "Widgets/input/SButton.h"

class SMyButton:public SButton
{
public:
	void Construct(const FArguments& InArgs);
private:
	FReply ButtonClicked();
};
