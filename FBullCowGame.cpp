#include "FBullCowGame.h"


FBullCowGame::FBullCowGame()
{
	reset();
}

int32 FBullCowGame::GetCurrentTries() const 
{ 
	return MyCurrentTry; 
}

FString FBullCowGame::GetMyHiddenWord()
{
	return MyHiddenWord;
}

int32 FBullCowGame::GetMyHiddenWordLength() const
{
	return MyHiddenWord.length();
}

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {4,8},{5,9},{6,10},{7,12},{8,15} };

	return WordLengthToMaxTries[GetMyHiddenWordLength()]; 
}


void FBullCowGame::reset()
{
	
	MyHiddenWord = GetWordInDictionary();
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

bool FBullCowGame::IsGameWon() const 
{
	return bGameIsWon;
}

FString FBullCowGame::GetWordInDictionary()
{
	int32 random = 0;
	srand(time(0));
	random = rand() % 19;
	TMap<int32, FString>WordInDictionary
	{
	{0,"drive"},
	{	1,"python" },
	{	2,"mouse"},
	{	3,"tela"},
	{	4,"tecla"},
	{	5,"site"},
	{	6,"cabo"},
	{	7,"cafe"},
	{	8,"github"},
	{	9,"blog"},
	{	10,"chat"},
	{	11,"chip"},
	{	12,"email"},
	{	13,"hacker"},
	{	14,"host"},
	{	15,"link"},
	{	16,"software"},
	{	17,"virus"},
	{18,"teclado"}
	};
	return WordInDictionary[random];
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!isLowerCase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetMyHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{

	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 WordLenght = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < WordLenght; MHWChar++)
	{
		for (int32 GChar = 0; GChar < WordLenght; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
					BullCowCount.BullCount++;
				else
					BullCowCount.CowCounts++;
			}

		}
	}
	if (BullCowCount.BullCount == WordLenght)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::isLowerCase(FString Guess) const
{
	for (auto Letter : Guess)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	if (Guess.length() <= 1)
	{
		return true;
	}

	TMap <char, bool> LetterSeen;

	for (auto Letter : Guess)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}
	return true;
}
