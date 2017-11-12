#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro(); // Print the introduction of the game

void PlayGame(); // Começa o jogo

FString GetGuess(); //Pega a resposta via teclado

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
	int32 CurrentyTry = BCGame.GetCurrentTries();
	
	for (int32 i = 0; i < MaxTries; ++i)
	{
		FString Guess = GetGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Tentativa "<< CurrentyTry++ <<" : " << Guess << std::endl;
		std::cout << "Bulls = " << BullCowCount.BullCount;
		std::cout << ". Cows = " << BullCowCount.CowCounts << std::endl;
	}
}

void PrintIntro()
{
	FString WordLength = BCGame.GetMyHiddenWord();
	
	std::cout << "Bem-Vindo ao jogo Bull and Cows" << std::endl;
	std::cout << "Voce consegue encontrar a palavra de " << WordLength.length() << " letras nao repetidas ?" << std::endl;

	std::cout << "Insira a palavra que voce acha ser a resposta: " << std::endl;
	return;

}


FString GetGuess()
{
	FString Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Deseja continuar jogando ? " << std::endl;
	FString Resposta;
	std::getline(std::cin, Resposta);
	return (Resposta[0] == 's') || (Resposta[0] == 'S');
}
