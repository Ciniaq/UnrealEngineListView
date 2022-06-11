// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

#include <string>

bool UMyBlueprintFunctionLibrary::StringComparator(FText A, FText B)
{
	std::string a = TCHAR_TO_UTF8(*A.ToString());
	std::string b = TCHAR_TO_UTF8(*B.ToString());

	if(a._Equal(b))
	{
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("A: %s, = B: %s"), *A.ToString(), *B.ToString()));

		return false;
	}
	int MinSize = 0;
	if(a.size()<b.size())
	{
		MinSize = a.size();
	}
	else
	{
		MinSize = b.size();
	}

	for(int i=0;i<MinSize;i++)
	{
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("i=%d"), i));


		if(int(a[i])<int(b[i]))
		{
			//if (GEngine)
			//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("A: %s, < B: %s"), *A.ToString(), *B.ToString()));
			return false;
		}
		else if (int(a[i]) > int(b[i]))
		{
			//if (GEngine)
			//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("A: %s, > B: %s"), *A.ToString(), *B.ToString()));
			return true;
		}
	}
	return false;
}
