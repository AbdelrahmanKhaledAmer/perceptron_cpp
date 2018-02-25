#include "../include/Perceptron.hpp"

int main(void)
{
    const int dataCount = 4;
    const int dataElems = 3;
    int epochCount = 0;
    float trainingData[dataCount][dataElems] = {{0, 0, 1}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int answers[4] = {-1, -1, -1, 1};
    Perceptron *p = new Perceptron(3, 0.05);
    while (1)
    {
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        PRINTLN("");
        int myGuess0 = p->guess(trainingData[0]);
        PRINT("For [0] and [0]: ");
        PRINTLN((myGuess0 == 1) ? 1 : 0);
        int myGuess1 = p->guess(trainingData[1]);
        PRINT("For [0] and [1]: ");
        PRINTLN((myGuess1 == 1) ? 1 : 0);
        int myGuess2 = p->guess(trainingData[2]);
        PRINT("For [1] and [0]: ");
        PRINTLN((myGuess2 == 1) ? 1 : 0);
        int myGuess3 = p->guess(trainingData[3]);
        PRINT("For [1] and [1]: ");
        PRINTLN((myGuess3 == 1) ? 1 : 0);
        if (myGuess0 == answers[0] && myGuess1 == answers[1] && myGuess2 == answers[2] && myGuess3 == answers[3])
        {
            break;
        }
        for (int i = 0; i < dataCount; i++)
        {
            p->train(trainingData[i], answers[i]);
        }
        epochCount++;
    }
    PRINTLN("");
    PRINT("Final number of epochs is: ");
    PRINTLN(epochCount);
    return 0;
}