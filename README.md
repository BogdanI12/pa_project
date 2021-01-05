# pa_project

### Configuration

MacBook Pro (15-inch, 2019)
Processor: 2,3 GHz 8-Core Intel Core i9
Memory: 16 GB 2400 MHz DDR4
Storage: 512 GB SSD

### Results

## Test 1
### Paramaters:
    Matrix: 2048 x 2048 
    Iterations: 8
    
#### Serial Version
        Duration 2800 miliseconds
        
#### MPI Version
        Proccess no:
        2 process - 440 miliseconds
        4 process - 320 miliseconds
        6 process - 310 miliseconds
        
#### OpenMP version
        Duration 61 miliseconds

# Test 2
### Paramaters:
    Matrix: 1024 x 1024 
    Iterations: 32
    
#### Serial Version
        Duration 604 miliseconds
        
#### MPI Version
        Proccess no:
        2 process - 290 miliseconds
        4 process - 190 miliseconds
        6 process - 170 miliseconds
        
#### OpenMP version
        Duration 65 miliseconds
        

# Test 3
### Paramaters:
    Matrix: 512 x 512 
    Iterations: 256
    
#### Serial Version
        Duration 970 miliseconds
        
#### MPI Version
        Proccess no:
        2 process - 250 miliseconds
        4 process - 180 miliseconds
        6 process - 140 miliseconds
        
#### OpenMP version
        Duration 137 miliseconds


### How to      
#### Compile Serial 
g++ GameOfLifeSerial.cpp -o serial_game

#### Compile OpenMP
clang++ -Xpreprocessor -fopenmp -I/usr/local/include -L/usr/local/lib -lomp  GameOfLifeOpenMP.cpp -o openmp_game
 
#### Compile and Run MPI
mpicxx -o mp_game GameOfLifeMPI.cpp
mpirun -np <no_process> ./mp_game

