//
//  GameOfLifeOpenMP.cpp
//  PA_Project
//
//  Created by Bogdan Iovan on 19/10/2020.
//

#include "defines.h"

#if RUNNING_MODE == 1
#define GameOfLifeOpenMP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include </usr/local/Cellar/libomp/11.0.0/include/omp.h>

#include <chrono>

using namespace std;
using namespace std::chrono;

int N, M;

char** current_iteration;
char** new_iteration;

void alloc_memory(string filename)
{
    ifstream f(filename);

    f>>N>>M;

    f.close();

    N = N + 2;
    M = M + 2;

    current_iteration = new char*[N];
    new_iteration = new char*[N];

    for(int i = 0; i<N; i++)
    {
        current_iteration[i] = new char[M];
    }

    for(int i = 0; i<N; i++)
    {
        new_iteration[i] = new char[M];
    }
}

void read_initial_state(string filename)
{
    ifstream f(filename);

    int dummy;

    f>>dummy>>dummy;

    for(int i = 1; i< N - 1; i++)
    {
        for(int j = 1; j< M - 1; j++)
        {
            f>>current_iteration[i][j];
        }
    }

    f.close();
}

void add_border()
{
    // top line
    #pragma omp parallel for
    for(int i = 1; i<M - 1; i++)
    {
        current_iteration[0][i] = current_iteration[N - 2][i];
    }

    // bottom line
    #pragma omp parallel for
    for(int i = 1; i<M - 1; i++)
    {
        current_iteration[N - 1][i] = current_iteration[1][i];
    }

    // left column
    #pragma omp parallel for
    for(int i = 1; i<N - 1; i++)
    {
        current_iteration[i][0] = current_iteration[i][M - 2];
    }

    // right column
    #pragma omp parallel for
    for(int i = 1; i<N - 1; i++)
    {
        current_iteration[i][M - 1] = current_iteration[i][1];
    }

    // corners
    current_iteration[0][0] = current_iteration[N - 2][M - 2]; // upper left
    current_iteration[0][M - 1] = current_iteration[N - 2][1]; // upper right
    current_iteration[N - 1][0] = current_iteration[1][M - 2]; // lower left
    current_iteration[N - 1][M - 1] = current_iteration[1][1]; // lower right
}

char analyze_cell(int i, int j)
{
    int alive_neighbours = 0, dead_neighbours = 0;

    current_iteration[i - 1][j - 1] == '.' ? dead_neighbours++ : alive_neighbours++;
    current_iteration[i - 1][j] == '.' ? dead_neighbours++ : alive_neighbours++;
    current_iteration[i - 1][j + 1] == '.' ? dead_neighbours++ : alive_neighbours++;
    current_iteration[i][j + 1] == '.' ? dead_neighbours++ : alive_neighbours++;
    current_iteration[i + 1][j + 1] == '.' ? dead_neighbours++ : alive_neighbours++;
    current_iteration[i + 1][j] == '.' ? dead_neighbours++ : alive_neighbours++;
    current_iteration[i + 1][j - 1] == '.' ? dead_neighbours++ : alive_neighbours++;
    current_iteration[i][j - 1] == '.' ? dead_neighbours++ : alive_neighbours++;

    if(alive_neighbours < 2)
        return '.';

    else if(alive_neighbours > 3)
        return '.';

    else if(current_iteration[i][j] == 'X' && (alive_neighbours == 2 || alive_neighbours == 3))
        return 'X';

    else if(current_iteration[i][j] == '.' && alive_neighbours == 3)
        return 'X';
    
    return 'X';
}

void apply_algorithm()
{
    int i, j = 0;

    #pragma omp parallel for
    for(i = 1; i<N - 1; i++)
    {
        for(j = 1; j<M - 1; j++)
        {
            new_iteration[i][j] = analyze_cell(i, j);
        }
    }
}

void copy_matrix()
{
    int i, j = 0;

    #pragma omp parallel for
    for(i = 1; i<N - 1; i++)
    {
        for(j = 1; j<M - 1; j++)
        {
            current_iteration[i][j] = new_iteration[i][j];
        }
    }
}

void write_final_state(string filename)
{
    ofstream f(filename);

    for(int i = 1; i<N - 1; i++)
    {
        for(int j = 1; j<M - 1; j++)
        {
            f<<current_iteration[i][j]<<" ";
        }
        f<<endl;
    }

    f.close();
}

int main(int argc, char** argv)
{
    cout<<"Running Open MP version"<<endl;
    
    auto start = high_resolution_clock::now();
    
    int iterations = ITERATIONS;
    
    alloc_memory(INPUT_FILE_PATH);
    
    read_initial_state(INPUT_FILE_PATH);
    
    #pragma omp parallel for
    for(int i = 0; i<iterations; i++)
    {
        add_border();

        apply_algorithm();

        copy_matrix();
    }

    write_final_state(OUTPUT_OPEN_MP_FILE_PATH);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<"Duration "<<duration.count()<<" milliseconds."<<endl;
}

#endif
