#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro(); // Print the introduction of the game

void PlayGame(); // Começa o jogo

FString GetValidGuess(); //Pega a resposta via teclado

bool AskToPlayAgain(); // Pergunta se Deseja continuar jogando

FBullCowGame BCGame;
int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	system("PAUSE");

	return 0;
}

void PlayGame()
{

	int32 MaxTries = BCGame.GetMaxTries();
	BCGame.reset();
	
	
	for (int32 i = 0; i < MaxTries; ++i)
	{
		FString Guess = GetValidGuess();

	}
}

void PrintIntro()
{
	int32 WordLength = BCGame.GetMyHiddenWordLength();
	
	std::cout << "Bem-Vindo ao jogo Bull and Cows" << std::endl;
	std::cout << "Voce consegue encontrar a palavra de " << WordLength << " letras nao repetidas ?" << std::endl;

	std::cout << "Insira a palavra que voce acha ser a resposta: " << std::endl;
	return;

}


FString GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	int32 CurrentyTry = BCGame.GetCurrentTries();
	do {	
		FString Guess = "";
		std::getline(std::cin, Guess);
		std::cout << "\nTentativa " << CurrentyTry << " : " << Guess << std::endl;
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::OK:
			std::cout << "Bulls = " << BullCowCount.BullCount;
			std::cout << ". Cows = " << BullCowCount.CowCounts << std::endl;
			CurrentyTry++;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Erro, Por Favor digite uma palavra sem letras repetidas " << std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Erro, Por Favor digite uma palavra de " << BCGame.GetMyHiddenWordLength() << " letras" << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Erro, Por Favor digite uma palavra sem letras maiusculas " << std::endl;
			break;
		default:
			return Guess;
		}std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
}

bool AskToPlayAgain()
{
	std::cout << "Deseja continuar jogando ? " << std::endl;
	FString Resposta;
	std::getline(std::cin, Resposta);
	return (Resposta[0] == 's') || (Resposta[0] == 'S');
}
