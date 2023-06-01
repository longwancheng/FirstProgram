#include "SMyCanvas.h"
#include "SMyButton.h"
#include "Widgets/Input/SComboBox.h"
#include "SMyTreeView.h"
void SMyCanvas::Construct(const FArguments& InArgs)
{
	SCanvas::Construct(InArgs);

	AddSlot()
		.Position(FVector2D(100, 100))
		.Size(FVector2D(100, 40))
		[
			SNew(SMyButton)
		];

	AddSlot()
		.Position(FVector2D(300, 100))
		.Size(FVector2D(100, 40))
		[
			SNew(SMyButton)
		];

	Options.Empty();
	Options.Add(MakeShareable(new FString("Apple")));
	Options.Add(MakeShareable(new FString("Pear")));
	Options.Add(MakeShareable(new FString("Orange")));
	AddSlot()
		.Position(FVector2D(500, 100))
		.Size(FVector2D(100, 40))
		[
			SNew(SComboBox<TSharedPtr<FString>>)
			.OptionsSource(&Options)//传入可以选择的选项。
			.OnGenerateWidget_Lambda([](TSharedPtr<FString> InValue){
				return SNew(STextBlock).Text(FText::FromString(*InValue));
			})//生成下拉框选项种的控件。
			.OnSelectionChanged_Lambda([this](TSharedPtr<FString> NewOption,ESelectInfo::Type SelectType) {
					CurrentSelect = Options.Find(NewOption);
			})//绑定Lambda表达式，当下拉框改变时调用。
			[	//绘制显示的控件
				SNew(STextBlock).Text_Lambda([this]() {
				if (CurrentSelect<0 || CurrentSelect>Options.Num() - 1)
					return FText::FromString(*Options[0]);
				else
					return FText::FromString(*Options[CurrentSelect]);
				})
			]
		];

	//添加水平布局
	AddSlot()
		.Position(FVector2D(100, 300))
		.Size(FVector2D(400, 80))
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.FillWidth(2.0f)
			[
				SNew(SButton)
			]
			+ SHorizontalBox::Slot()[
				SNew(SButton)
			]
			+ SHorizontalBox::Slot()[
				SNew(SButton)
			]
		];
	//添加垂直布局
	AddSlot()
		.Position(FVector2D(100, 500))
		.Size(FVector2D(100, 200))
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.FillHeight(2.f)
			[
				SNew(SButton)
			]
			+SVerticalBox::Slot()
			[
				SNew(SButton)
			]
			+SVerticalBox::Slot()
			[
				SNew(SButton)
			]
		];
	//添加树视图
	AddSlot()
		.Position(FVector2D(300, 500))
		.Size(FVector2D(300, 400))
		[
			SNew(SMyTreeView)
		];
}
