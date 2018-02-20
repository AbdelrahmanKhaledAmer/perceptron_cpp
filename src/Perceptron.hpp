#ifndef PERCEPTRON_HPP
#define PERCEPTRON_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>

#define PRINT(m)          \
    {                     \
        std::cout << (m); \
    }
#define PRINTLN(m)                     \
    {                                  \
        std::cout << (m) << std::endl; \
    }

class Perceptron
{
  private:
    int sizeOfWeights_;

  public:
    float *weights;
    float learningRate;

    Perceptron(int, float);
    ~Perceptron();

    void train(float *, float);
    int guess(float *);
};

#endif