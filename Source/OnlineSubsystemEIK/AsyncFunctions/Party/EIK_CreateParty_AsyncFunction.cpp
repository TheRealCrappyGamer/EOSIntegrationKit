// Copyright (c) 2023 Betide Studio. All Rights Reserved.


#include "EIK_CreateParty_AsyncFunction.h"

#include "OnlineSubsystem.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "Interfaces/OnlineStatsInterface.h"
#include "OnlineSubsystemEIK/Subsystem/EIK_Subsystem.h"
#include "Online/OnlineSessionNames.h"

void UEIK_CreateParty_AsyncFunction::Activate()
{
	CreateParty();
	Super::Activate();
}

void UEIK_CreateParty_AsyncFunction::CreateParty()
{
	if (const IOnlineSubsystem* SubsystemRef = Online::GetSubsystem(this->GetWorld()))
	{
		if (const IOnlinePartyPtr PartyPtrRef = SubsystemRef->GetPartyInterface())
		{
			TSharedRef<FPartyConfiguration> Config = MakeShared<FPartyConfiguration>();

			PartyPtrRef->CreateParty(0, 32, *Config);
		}
	}
}

void UEIK_CreateParty_AsyncFunction::OnCreatePartyCompleted(bool bWasSuccessful, int32 PartyId)
{
	
}

UEIK_CreateParty_AsyncFunction* UEIK_CreateParty_AsyncFunction::CreateEIKParty(FPartyConfiguration PartyConfiguration, TMap<FString, FEIKAttribute> PartyAttributes)
{
	UEIK_CreateParty_AsyncFunction* Ueik_CreatePartyObject = NewObject<UEIK_CreateParty_AsyncFunction>();
	Ueik_CreatePartyObject->Var_PartyConfiguration = PartyConfiguration;
	Ueik_CreatePartyObject->PartyAttributes = PartyAttributes;
	return Ueik_CreatePartyObject;
}