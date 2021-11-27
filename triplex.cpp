#include <iostream>
#include <stdlib.h>
#include <ctime>

void PrintIntroduction(int Difficulty,int Lives)
{
   std :: cout << "\n\nShhh....You Are Secret Agent In A Room Level " << Difficulty << std ::  endl;
   std :: cout << "Enter A Correct Code To Continue...." << std :: endl;
   std :: cout << "\nLives : " << Lives << std :: endl;
}

bool PlayGame(int Difficulty,int Lives)
{
   PrintIntroduction(Difficulty,Lives);

   std :: cout << std :: endl;
   const int CodeA  = rand() % Difficulty + Difficulty;
   const int CodeB = rand() % Difficulty + Difficulty;
   const int CodeC = rand() % Difficulty + Difficulty;

   const int CodeSum = CodeA+CodeB+CodeC;
   const int CodeMul = CodeA*CodeB*CodeC;

   std :: cout << "+ There Are 3 Number In A Code" << std :: endl;
   std :: cout << "+ The Code Add-up To : " << CodeSum << std :: endl;
   std :: cout << "+ The Code Multiply To Given : " << CodeMul << std :: endl ;

   int GuessA;
   int GuessB;
   int GuessC;

   std :: cout << "Enter Your Code : ";
   std :: cin >> GuessA; 
   std :: cin >> GuessB;
   std :: cin >> GuessC;

   int GuessSum = GuessA + GuessB + GuessC;
   int GuessProduct = GuessA * GuessB * GuessC;

   if (GuessSum == CodeSum && GuessProduct == CodeMul)
   {
      system("CLS");
      std :: cout << "\n ***Your Code is Correct !***";
      return true;
   }
   else
   {
      system("CLS");
      std ::cout << "\nSorry U Enter Wrong Code";
      return false;
   }
}

int main()
{
   srand(time(NULL));
   
   int GameDifficulty = 1;
   int GameLives = 5;
   const int MaxLevel = 4;
   while ((GameDifficulty <= MaxLevel) && (GameLives >0) )
   {
      bool bLevelComplete = PlayGame(GameDifficulty,GameLives);
      std :: cin.clear();
      std :: cin.ignore();

      if (bLevelComplete)
      {
         ++GameDifficulty;
         if (GameDifficulty > MaxLevel)
         {
            std :: cout << "\n\n***You Win....Your Game Is Over Thanks For Playing***";
         }   
      }
      if (bLevelComplete == false)
      {
         --GameLives;
         if (GameLives == 0)
         {
            std :: cout << "\n\n***Haha,You Noob YOU Loose Start Your Game Again***";
         }
         
      }    
   }
   return 0;
}
