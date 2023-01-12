#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>
#include <limits>

// SDL library
#include <SDL2/SDL.h>

// Function prototypes
void menu();
void draw_states(std::vector<int> &, SDL_Renderer *,
                 unsigned int, unsigned int);

int validate_input(int);
void end_program();

// Sorting Algorithms

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
            for (unsigned int i{}; i < data_vec.size(); ++i)
            {
                for (unsigned j{i}; j < data_vec.size(); ++j)
                {
                    if (data_vec[j] < data_vec[i])
                        std::swap(data_vec[j], data_vec[i]);

                    SDL_SetRenderDrawColor(
                        renderer, 0, 0, 0, 255);
                    SDL_RenderClear(renderer);

                    draw_states(data_vec, renderer, i, j);

                    SDL_RenderPresent(renderer);
                    SDL_Delay(5);
                }
            }

            break;

        case 6:
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

    std::cout << "1. Bubble Sort Algorithm \n2. Selection Sort Algorithm"
              << "\n3. Insertion Sort Algorithm \n4. Quick Sort Algorithm"
              << "\n5. Merge Sort Algorithm \n6. Quit Application" << std::endl;
}

/**
 * @brief
 * Draw the states of the sorting algorithm in the screen.
 * @param data_vec Vector with the data
 * @param renderer Renderer where the render happens
 * @param red Red color
 * @param blue Blue color
 */
void draw_states(std::vector<int> &data_vec, SDL_Renderer *renderer,
                 unsigned int red, unsigned int blue)
{
    int index{};

    for (auto i : data_vec)
    {
        if (index == red)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        else if (index == blue)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderDrawLine(renderer, index, 99, index, i);
        ++index;
    }
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