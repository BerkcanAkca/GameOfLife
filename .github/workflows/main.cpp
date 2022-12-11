// GameOfLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstddef>


void CheckInput(int a)
{
    while (true)
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input\nTry Again" << std::endl;
            std::cin >> a;
        }
        if (!std::cin.fail() && a > 0)
            break;
    }
}

int main()
{
    int x;
    int y;
    int lifePoints = 0;

    std::cout << "Enter Grid X Size: ";
    std::cin >> x;
    CheckInput(x);
    x = std::min<int>(315, x);
    x += 2;
    std::system("cls");
   

    std::cout << "Enter Grid Y Size: ";
    std::cin >> y;
    CheckInput(y);
    y = std::min<int>(82, y);
    y += 2;
    std::system("cls");

   
    std::vector<std::vector<bool>> Grid(x, std::vector<bool>(y));

    for (int i = 1; i < x - 1; i++)
    {
        for (int j = 1; j < y - 1; j++)
        {
                Grid[i][j] = rand() % 2;
        }
    }

    while (true)
    {
        std::cin.ignore();
        std::system("cls");

        //Display
        for (int j = 0; j < y; j++)
        {
            for (int i = 0; i < x; i++)
            {

                std::cout << Grid[i][j];

            }
            std::cout << "" << std::endl;
        }

        //Calculate the Next Round
        for (int j = 1; j < y - 1; j++)
        {
            for (int i = 1; i < x - 1; i++)
            {
                lifePoints = 0;

                if (Grid[i - 1][j - 1])
                    lifePoints++;
                if (Grid[i - 1][j])
                    lifePoints++;
                if (Grid[i - 1][j + 1])
                    lifePoints++;


                if (Grid[i][j - 1])
                    lifePoints++;
                if (Grid[i][j + 1])
                    lifePoints++;


                if (Grid[i + 1][j - 1])
                    lifePoints++;
                if (Grid[i + 1][j])
                    lifePoints++;
                if (Grid[i + 1][j + 1])
                    lifePoints++;

                //If DEAD

                if (Grid[i][j] == 0)
                {
                    if (lifePoints == 3)
                    {
                        Grid[i][j] = 1;
                        continue;
                    }    
                }
                else  //If ALIVE
                {
                    if (lifePoints < 2 || lifePoints > 3)
                        Grid[i][j] = 0;

                }

            }
        }

    }  

}
