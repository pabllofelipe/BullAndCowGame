#pragma once
#include <string>


using FString = std::string;

using int32 = int;

struct FBullCowCount
{
	int32 BullCount = 0;
	int32 CowCounts = 0;
};
class FBullCowGame
{
public:

	FBullCowGame();
	void reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTries() const;
	FString GetMyHiddenWord();
	bool IsGameWon() const;
	bool CheckGuessValidity(FString);
	FBullCowCount SubmitGuess(FString);

private:

	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

};