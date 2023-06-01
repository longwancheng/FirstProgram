#pragma once
#include "CoreMinimal.h"
#include "Widgets/Views/STreeView.h"
#include "SMyTreeView.generated.h"
UCLASS()
class UTreeItemData : public UObject 
{
	GENERATED_BODY()
public:
	FString MyName;
	float MyHeight;

	TArray<TSharedPtr<UTreeItemData>> Children;
};

class SMyTreeView : public STreeView<TSharedPtr<UTreeItemData>> //传入类型，表示由什么数据类型生成
{
public:
	void Construct(const FArguments& InArgs);

	TArray<TSharedPtr<UTreeItemData>> TreeItemDatas;

	TSharedRef<ITableRow> GenerateRowItem(TSharedPtr<UTreeItemData> InTreeItemData,const TSharedRef<STableViewBase>& OwnerTable);

	void GetChildren(TSharedPtr<UTreeItemData> InTreeItem,TArray<TSharedPtr<UTreeItemData>>& OnChildren);
};