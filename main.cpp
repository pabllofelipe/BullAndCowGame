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

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTries() <= MaxTries)
	{
		FString Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.BullCount;
		std::cout << ". Cows = " << BullCowCount.CowCounts << std::endl;
		if (BCGame.IsGameWon())
		{
			std::cout << "\n\n* * * * P A R A B E N S --- V O C E   D E S C O B R I U  A  P A L A V R A   S E C R E T A  * * * *\n\n" << std::endl;
		}
		else
		{
			if (BCGame.GetCurrentTries() > 10)
				std::cout << "\n\n* * * * V O C E   P E R D E U * * * *\n\n" << std::endl;
		}
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
	FString Guess = "";
	do {	

		std::getline(std::cin, Guess);
		std::cout << "\nTentativa " << BCGame.GetCurrentTries() << " : " << Guess << std::endl;
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::OK:
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
			break;
		}std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Deseja continuar jogando ? (s/n) " << std::endl;
	FString Resposta;
	std::getline(std::cin, Resposta);
	return (Resposta[0] == 's') || (Resposta[0] == 'S');
}
