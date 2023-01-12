#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>
#include <limits>

// SDL library
#include <SDL2/SDL.h>

// Sorts
#include "sorts.h"

// Function prototypes
void menu();
int validate_input(int);
void end_program();

// Main function
int main(int argc, char **argv)
{
    // Unused argc, argv
    (void)argc;
    (void)argv;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Error: SDL2 could not be initialized" << std::endl;
        printf("SDL ERROR: %s", SDL_GetError());

        return EXIT_FAILURE;
    }

    // Window
    const int window_width{500};
    const int window_height{500};

    SDL_Window *window{SDL_CreateWindow("Sorting Algorithm Visualizer",
                                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                        window_width, window_height,
                                        0)};

    if (!window)
    {
        std::cout << "Error: window could not be initialized\n";
        printf("SDL ERROR: %s", SDL_GetError());

        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer{SDL_CreateRenderer(window, -1,
                                              SDL_RENDERER_SOFTWARE |
                                                  SDL_RENDERER_PRESENTVSYNC)};

    if (renderer == nullptr || !renderer)
    {
        std::cout << "Error: could not create renderer for main window."
                  << std::endl;
        printf("SDL ERROR: %s", SDL_GetError());

        return EXIT_FAILURE;
    }

    SDL_RenderSetScale(renderer, 5, 5);

    std::random_device rng;
    std::uniform_int_distribution d(1, 99);

    std::vector<int> data_vec;

    // Filling the data
    for (int i{}; i < 100; ++i)
        data_vec.push_back(d(rng));

    std::vector<int> desorganized_data{data_vec};

    // Output (desorganized)
    std::cout << "Generated vector: " << std::endl;

    for (auto i : data_vec)
        std::cout << i << " ";

    std::cout << std::endl;

    // Sorting
    bool running{true};

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
                break;
            }
        }

        menu();

        std::cout << "Choose the algorithm you wish to see: ";
        int option{validate_input(option)};

        switch (option)
        {
        case 1:
            bubble_sort_ascending(data_vec, renderer);
            data_vec = desorganized_data;

            break;

        case 2:
            bubble_sort_descending(data_vec, renderer);
            data_vec = desorganized_data;

            break;

        case 3:
            selection_sort_ascending(data_vec, renderer);
            data_vec = desorganized_data;

            break;

        case 4:
            selection_sort_descending(data_vec, renderer);
            data_vec = desorganized_data;

            break;

        case 5:
            insertion_sort_ascending(data_vec, renderer);
            data_vec = desorganized_data;

            break;

        case 6:
            insertion_sort_descending(data_vec, renderer);
            data_vec = desorganized_data;

            break;

        case 7:
            data_vec = desorganized_data;

            break;

        case 8:
            data_vec = desorganized_data;

            break;

        case 9:
            data_vec = desorganized_data;

            break;

        case 10:
            data_vec = desorganized_data;

            break;

        case 11:
            std::cout << "Closign application" << std::endl;
            running = false;
            break;
        }
    }

    end_program();
}

// Function Declaration
/**
 * @brief
 * Shows a simple menu to the user
 */
void menu()
{
    std::cout << "---- Sorting Algorithms Visualizer ----" << std::endl;

    std::cout << "1. Bubble Sort (Ascending) Algorithm "
              << "\n2. Bubble Sort (Descending) Algorithm "
              << "\n3. Selection Sort (Ascending) Algorithm"
              << "\n4. Selection Sort (Descending) Algorithm"
              << "\n5. Insertion Sort (Ascending) Algorithm"
              << "\n6. Insertion Sort (Descending) Algorithm"
              << "\n7. Quick Sort (Ascending) Algorithm"
              << "\n8. Quick Sort (Descending) Algorithm"
              << "\n9. Merge Sort (Ascending) Algorithm"
              << "\n10. Merge Sort (Descending) Algorithm"
              << "\n11. Quit Application" << std::endl;
}

/**
 * @brief
 * Validates the user input. If the input is correct, returns the value.
 * Otherwise, asks the user for another input.
 * @param input User input to be validated
 * @return int Input validated.
 */
int validate_input(int input)
{
    while (!(std::cin >> input))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n');

        std::cout << "Invalid input. Try again: ";
    }

    return input;
}

/**
 * @brief
 * Ends the program.
 * @param window Window to be destroyed
 * @param renderer Renderer to be destroyed.
 */
void end_program()
{
    SDL_DestroyWindow(SDL_GL_GetCurrentWindow());

    SDL_DestroyRenderer(
        SDL_GetRenderer(SDL_GL_GetCurrentWindow()));

    SDL_Quit();
}