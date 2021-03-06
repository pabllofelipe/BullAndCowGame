#pragma once
#include <iostream>
#include <string>
#include <map>
#include <time.h>
#define TMap std::map


using FString = std::string;

using int32 = int;

struct FBullCowCount
{
	int32 BullCount = 0;
	int32 CowCounts = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};



class FBullCowGame
{
public:

	FBullCowGame();
	void reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTries() const;
	FString GetMyHiddenWord();
	int GetMyHiddenWordLength() const;
	bool IsGameWon() const;
	FString GetWordInDictionary();
	EGuessStatus CheckGuessValidity(FString) const;
	FBullCowCount SubmitValidGuess(FString);

private:

	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool isLowerCase(FString) const;
	bool IsIsogram(FString) const;

};