// Copyright (c) 2023 Betide Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnlineError.h"
#include "EIK_CreateParty_AsyncFunction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCreateParty_Delegate, bool, bWasSuccessful, int32, PartyId);

UCLASS()
class ONLINESUBSYSTEMEIK_API UEIK_CreateParty_AsyncFunction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, DisplayName = "Success")
	FCreateParty_Delegate OnSuccess;
	UPROPERTY(BlueprintAssignable, DisplayName = "Failure")
	FCreateParty_Delegate OnFail;

	bool bDelegateCalled = false;

	virtual void Activate() override;

	virtual void CreateParty();

	void OnCreatePartyCompleted(bool bWasSuccessful, int32 PartyId);

	UFUNCTION(BlueprintCallable, DisplayName = "Create EIK Party", meta = (BlueprintInternalUseOnly = "true"), Category = "EOS Integration Kit || Party")
	static UEIK_CreateParty_AsyncFunction* CreateEIKParty(FPartyConfiguration PartyConfiguration, TMap<FString, FEIKAttribute> PartyAttributes);

};
