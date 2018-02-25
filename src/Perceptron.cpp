#include "../include/Perceptron.hpp"

Perceptron::Perceptron(int numberOfInputs, float learningRate)
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_real_distribution<> distr(-1, 1);
    for (int i = 0; i < numberOfInputs - 1; i++)
    {
        weights.push_back(distr(eng));
    }
    weights.push_back(1);
    this->learningRate = learningRate;
}

Perceptron::~Perceptron() {}

int Perceptron::guess(float *inputs)
{
    float sum = 0;
    for (int i = 0; i < this->weights.size(); i++)
    {
        sum += inputs[i] * weights[i];
    }
    if (sum >= 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void Perceptron::train(float *inputs, float answer)
{
    int prediction = guess(inputs);
    float error = answer - prediction;
    for (int i = 0; i < this->weights.size(); i++)
    {
        weights[i] += error * inputs[i] * this->learningRate;
    }
}