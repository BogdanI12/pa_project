# pa_project

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

### MPI Version

```
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int rank_size;
    MPI_Comm_size(MPI_COMM_WORLD, &rank_size);

    // Get the rank of the process
    int rank_no;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank_no);

    // if rank_no == 1/2/3/4/5.... { execute something; }
    
    // Finalize the MPI environment.
    MPI_Finalize();

```

### Quick intro to OpenMP
https://bisqwit.iki.fi/story/howto/openmp/

### Compile Serial 
g++ GameOfLifeSerial.cpp -o serial_game

### Compile OpenMP
 clang++ -Xpreprocessor -fopenmp -I/usr/local/include -L/usr/local/lib -lomp  GameOfLifeOpenMP.cpp -o openmp_game
 
 ### Compile MPI
mpicxx -o mp_game GameOfLifeMPI.cpp

mpirun -np 7./mp_game

