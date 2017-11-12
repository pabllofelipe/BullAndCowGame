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
	FString Word = BCGame.GetMyHiddenWord();
	
	std::cout << "Bem-Vindo ao jogo Bull and Cows\n" << std::endl;
	std::cout << "                 }   {         ___ " << std::endl;
	std::cout << "                 (o o)        (o o) " << std::endl;
	std::cout << "          /-------\\ /          \\ /-------\\		 " << std::endl;
	std::cout << "         / | BULL |O            O| COW  | \\			" << std::endl;
	std::cout << "        *  |-,--- |              |------|  *			" << std::endl;
	std::cout << " _\\|/_    ^      ^     _\\|/_    ^      ^    _\\|/_\n" << std::endl;
	std::cout << "Voce tem "<< BCGame.GetMaxTries() << " tentativas para conseguir descobrir a palavra secreta\n " << std::endl;
	std::cout << "* * * D I C A * * *: contem " << Word.length() << " letras nao repetidas\n" << std::endl;

	std::cout << "Insira a palavra que voce acha ser a resposta: " << std::endl;
	return;

}


FString GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FString Guess = "";
	do {	

		std::getline(std::cin, Guess);
		std::cout << "\nTentativa " << BCGame.GetCurrentTries() << " de " << BCGame.GetMaxTries() << " : " << Guess << std::endl;
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::OK:
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Erro, Por Favor digite uma palavra sem letras repetidas\n " << std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Erro, Por Favor digite uma palavra de " << BCGame.GetMyHiddenWordLength() << " letras\n" << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Erro, Por Favor digite uma palavra sem letras maiusculas\n " << std::endl;
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
