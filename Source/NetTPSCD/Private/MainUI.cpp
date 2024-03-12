﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUI.h"
#include "Components/Image.h"
#include "Components/UniformGridPanel.h"

void UMainUI::SetActiveCrosshair( bool bActive )
{
	// 만약 크로스헤어 이미지를 bActive가 true라면 보이고 false면 안보이게 하고싶다.
	// 플레이어가 태어날때 안보이게
	// 총 집으면 보이게
	// 총 놓으면 안보이게
	if (bActive)
	{
		ImageCrosshair->SetVisibility( ESlateVisibility::Visible );
		grid_bullet->SetVisibility( ESlateVisibility::Visible );
	}
	else
	{
		ImageCrosshair->SetVisibility( ESlateVisibility::Hidden );
		grid_bullet->SetVisibility( ESlateVisibility::Hidden );
	}
}

void UMainUI::ReloadBulletUI( int32 maxBulletCount )
{
	// 기존에 grid_bullet의 자식들을 모두 삭제하고
	grid_bullet->ClearChildren();
	// 다시 maxBulletCount만큼 생성하고싶다.
	for (int32 i = 0; i < maxBulletCount; i++)
	{
		AddBulletUI();
	}
}

void UMainUI::AddBulletUI()
{
	// 총알 위젯을 만들고
	auto bulletUI = CreateWidget( this , bulletUIFactory );
	// grid에 자식으로 붙인다.
	grid_bullet->AddChildToUniformGrid( bulletUI , 0 , grid_bullet->GetChildrenCount() );
}

// index는 0부터 시작한다.
void UMainUI::RemoveBulletUI(int32 index)
{
	// grid의 index위치의 자식을 제거한다.
	grid_bullet->RemoveChildAt( index );
}

void UMainUI::PlayHitAnim()
{
	PlayAnimation( HitAnime);
	
}
