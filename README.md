# pa_project

<<<<<<< HEAD
### Results

### Serial Version
        Matrix: 256x256
        Iterations: 500
        Duration 475 mmiliseconds

### OpenMP version
        Matrix: 256x256
        Iterations: 500
        Duration 131 mmiliseconds

```
// every checking of the matrix has been done in a separate thread
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
```

### Quick intro to OpenMP
https://bisqwit.iki.fi/story/howto/openmp/

### Comile Serial 
=======
### Compile Serial 
>>>>>>> 81b4de1262cb057470b692260368af180b44bb72
g++ GameOfLifeSerial.cpp -o serial_game

### Compile OpenMP
 clang++ -Xpreprocessor -fopenmp -I/usr/local/include -L/usr/local/lib -lomp  GameOfLifeOpenMP.cpp -o openmp_game

