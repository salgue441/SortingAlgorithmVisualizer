/**
 * @file sorts.h
 * @author Carlos Salguero
 * @brief Implementations of sorting algorithms
 * @version 0.1
 * @date 2023-01-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>
#include <iterator>

// SDL Libraries
#include <SDL2/SDL.h>

// Auxiliary Functions
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

// Sort Functions
/**
 * @brief
 * Bubble Sort Algorithm (ascending)
 * @tparam T Type of vector's data
 * @param data_vec Vector with data to be rendered
 * @param renderer Renders the data into the window
 */
template <typename T>
void bubble_sort_ascending(std::vector<T> &data_vec, SDL_Renderer *renderer)
{
    for (unsigned int i{}; i < data_vec.size(); ++i)
    {
        for (unsigned int j{}; j < data_vec.size() - 1; ++j)
        {
            if (data_vec.at(j) > data_vec.at(i))
                std::swap(data_vec.at(j), data_vec.at(i));

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            draw_states(data_vec, renderer, i, j);

            SDL_RenderPresent(renderer);
            SDL_Delay(1);
        }
    }

    SDL_RenderClear(renderer);
}

/**
 * @brief
 * Bubble Sort Algorithm (descending)
 * @tparam T Type of vector's data
 * @param data_vec Vector with data to be rendered
 * @param renderer Renders the data into the window
 */
template <typename T>
void bubble_sort_descending(std::vector<T> &data_vec, SDL_Renderer *renderer)
{
    for (unsigned int i{}; i < data_vec.size(); ++i)
    {
        for (unsigned int j{}; j < data_vec.size() - 1; ++j)
        {
            if (data_vec.at(j) < data_vec.at(i))
                std::swap(data_vec.at(i), data_vec.at(j));

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            draw_states(data_vec, renderer, i, j);

            SDL_RenderPresent(renderer);
            SDL_Delay(1);
        }
    }

    SDL_RenderClear(renderer);
}

/**
 * @brief
 * Selection Sort Algorithm (ascending)
 * @tparam T Type of vector's data
 * @param data_vec Vector with data to be rendered
 * @param renderer Renders the data into the window
 */
template <typename T>
void selection_sort_ascending(std::vector<T> &data_vec,
                              SDL_Renderer *renderer)
{
    for (unsigned int i{}; i < data_vec.size() - 1; ++i)
    {
        auto min{i};

        for (unsigned int j{i + 1}; j < data_vec.size(); ++j)
        {
            if (data_vec.at(j) < data_vec.at(min))
                min = j;
        }

        if (min != i)
            std::swap(data_vec.at(min), data_vec.at(i));

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        draw_states(data_vec, renderer, i, min);

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    SDL_RenderClear(renderer);
}

/**
 * @brief
 * Selection Sort Algorithm (descending)
 * @tparam T Type of vector's data
 * @param data_vec Vector with data to be rendered
 * @param renderer Renders the data into the window
 */
template <typename T>
void selection_sort_descending(std::vector<T> &data_vec,
                               SDL_Renderer *renderer)
{
    for (unsigned int i{}; i < data_vec.size() - 1; ++i)
    {
        auto max{i};

        for (unsigned int j{i + 1}; j < data_vec.size(); ++j)
        {
            if (data_vec.at(j) > data_vec.at(max))
                max = j;
        }

        if (max != i)
            std::swap(data_vec.at(max), data_vec.at(i));

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        draw_states(data_vec, renderer, i, max);

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    SDL_RenderClear(renderer);
}

/**
 * @brief
 * Insertion Sort Algorithm (ascending)
 * @tparam T Type of vector's data
 * @param data_vec Vector with data to be rendered
 * @param renderer Renders the data into the window
 */
template <typename T>
void insertion_sort_ascending(std::vector<T> &data_vec, SDL_Renderer *renderer)
{
    for (unsigned int i{1}; i < data_vec.size(); ++i)
    {
        for (unsigned int j{i};
             j > 0 && data_vec.at(j) < data_vec.at(j - 1); --j)
        {
            std::swap(data_vec.at(j), data_vec.at(j - 1));

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            draw_states(data_vec, renderer, i, j);

            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
    }

    SDL_RenderClear(renderer);
}

/**
 * @brief
 * Insertion Sort Algorithm (descending)
 * @tparam T Type of vector's data
 * @param data_vec Vector with data to be rendered
 * @param renderer Renders the data into the window
 */
template <typename T>
void insertion_sort_descending(std::vector<T> &data_vec, SDL_Renderer *renderer)
{
    for (unsigned int i{1}; i < data_vec.size(); ++i)
    {
        for (unsigned int j{i};
             j > 0 && data_vec.at(j) > data_vec.at(j - 1); --j)
        {
            std::swap(data_vec.at(j - 1), data_vec.at(j));

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            draw_states(data_vec, renderer, i, j);

            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
    }

    SDL_RenderClear(renderer);
}

template <typename T>
T partition(std::vector<T> &data_vec, unsigned int low, unsigned int high)
{
    auto i{low - 1};
    auto pivot = data_vec.at(high);

    for (unsigned int j{low}; j < high; ++j)
    {
        if (data_vec.at(j) <= pivot)
        {
            ++i;
            std::swap(data_vec.at(i), data_vec.at(j));
        }
    }

    std::swap(data_vec.at(i + 1), data_vec.at(high));

    return i + 1;
}

/**
 * @brief
 * Quick Sort Algorithm (ascending)
 * @tparam T Type of vector's data
 * @param data_vec Vector with data to be rendered
 * @param renderer Renders the data into the window
 */
template <typename T>
void quick_sort_ascending(std::vector<T> &data_vec, SDL_Renderer *renderer)
{
    auto low{0};
    auto high{data_vec.size() - 1};

    if (low < high)
    {
        auto pivot = partition(data_vec, low, high);

        quick_sort_ascending(data_vec, low, pivot - 1);
        quick_sort_ascending(data_vec, pivot + 1, high);
    }
}

/**
 * @brief
 * Quick Sort Algorithm (descending)
 * @tparam T Type of vector's data
 * @param data_vec Vector with data to be rendered
 * @param renderer Renders the data into the window
 */
template <typename T>
void quick_sort_descending(std::vector<T> &data_vec, SDL_Renderer *renderer)
{
}

#endif //! SORTS_H
