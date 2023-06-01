#include "SMyTreeView.h"

void SMyTreeView::Construct(const FArguments& InArgs)
{
	FArguments Arguments = InArgs;

	TSharedPtr<UTreeItemData> ZhangSan = MakeShareable(NewObject<UTreeItemData>());
	ZhangSan->MyName = FString("ZhangSan");
	ZhangSan->MyHeight = 1.0f;
	TSharedPtr<UTreeItemData> LiSi = MakeShareable(NewObject<UTreeItemData>());
	LiSi->MyName = FString("LiSi");
	TSharedPtr<UTreeItemData> ZhangSan1 = MakeShareable(NewObject<UTreeItemData>());
	ZhangSan1->MyName = FString("ZhangSan1");
	TSharedPtr<UTreeItemData> ZhangSan2 = MakeShareable(NewObject<UTreeItemData>());
	ZhangSan2->MyName = FString("ZhangSan2");
	TSharedPtr<UTreeItemData> ZhangSan3 = MakeShareable(NewObject<UTreeItemData>());
	ZhangSan3->MyName = FString("ZhangSan3");
	ZhangSan->Children.Add(ZhangSan1);
	ZhangSan->Children.Add(ZhangSan2);
	ZhangSan->Children.Add(ZhangSan3);
	TSharedPtr<UTreeItemData> LiSi1 = MakeShareable(NewObject<UTreeItemData>());
	LiSi1->MyName = FString("LiSi1");
	TSharedPtr<UTreeItemData> LiSi2 = MakeShareable(NewObject<UTreeItemData>());
	LiSi2->MyName = FString("LiSi2");
	TSharedPtr<UTreeItemData> LiSi3 = MakeShareable(NewObject<UTreeItemData>());
	LiSi3->MyName = FString("LiSi3");
	LiSi->Children.Add(LiSi1);
	LiSi->Children.Add(LiSi2);
	LiSi->Children.Add(LiSi3);
	//添加数据源	

	TreeItemDatas.Add(ZhangSan);
	TreeItemDatas.Add(LiSi);

	Arguments.TreeItemsSource(&TreeItemDatas);
	Arguments.OnGenerateRow_Raw(this,&SMyTreeView::GenerateRowItem);
	Arguments.OnGetChildren_Raw(this,&SMyTreeView::GetChildren);
	STreeView::Construct(Arguments);
}

TSharedRef<ITableRow> SMyTreeView::GenerateRowItem(TSharedPtr<UTreeItemData> InTreeItemData, const TSharedRef<STableViewBase>& OwnerTable)
{
	return SNew(STableRow<TSharedPtr<UTreeItemData>>, OwnerTable)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(STextBlock)
				.Text(FText::FromString(InTreeItemData->MyName))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(STextBlock)
				.Text(FText::FromString(FString::SanitizeFloat(InTreeItemData->MyHeight)))
			]
		];
}

void SMyTreeView::GetChildren(TSharedPtr<UTreeItemData> InTreeItem, TArray<TSharedPtr<UTreeItemData>>& OnChildren)
{
	OnChildren = InTreeItem->Children;
}
