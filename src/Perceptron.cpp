#include "Perceptron.hpp"

Perceptron::Perceptron(int numberOfInputs, float learningRate)
{
    this->sizeOfWeights_ = numberOfInputs;
    this->weights = new float(numberOfInputs);
    if (this->weights == NULL)
    {
        std::cout << "OUT OF MEMORY" << std::endl;
        std::exit(-1);
    }
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_real_distribution<> distr(-1, 1);
    for (int i = 0; i < numberOfInputs; i++)
    {
        weights[i] = distr(eng);
    }
    weights[numberOfInputs - 1] = 1;
    this->learningRate = learningRate;
}

Perceptron::~Perceptron()
{
    delete this->weights;
}

int Perceptron::guess(float *inputs)
{
    float sum = 0;
    for (int i = 0; i < this->sizeOfWeights_; i++)
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
    for (int i = 0; i < this->sizeOfWeights_; i++)
    {
        weights[i] += error * inputs[i] * this->learningRate;
    }
}