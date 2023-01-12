#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>

// SDL libraries
#include <SDL2/SDL.h>

// Sorting Algorithms

int main(int argc, char **argv)
{
    std::random_device rng;
    std::uniform_int_distribution d(1, 99);

    std::vector<int> data_vector;

    // Fill the vector with random numbers
    for (int i{}; i < 100; ++i)
        data_vector.push_back(d(rng));

    // SDL window
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    SDL_CreateWindowAndRenderer(
        100 * 10, 100 * 10, 0,
        &window, &renderer);

    SDL_RenderSetScale(renderer, 10, 10);

    // Sorting
    for (unsigned int i{}; i < data_vector.size(); ++i)
        for (unsigned j{i}; j < data_vector.size(); ++j)
            if (data_vector[j] < data_vector[i])
                std::swap(data_vector[j], data_vector[i]);

    // Print the vector
    for (auto i : data_vector)
        std::cout << i << " ";

    std::cout << std::endl;

    (std::ranges::is_sorted(data_vector))
        ? std::cout << "Sorted \n"
        : std::cout << "Not sorted \n";
}
