# pa_project

### Comile Serial 
g++ GameOfLifeSerial.cpp -o serial_game

### Compile OpenMP
 clang++ -Xpreprocessor -fopenmp -I/usr/local/include -L/usr/local/lib -lomp  GameOfLifeOpenMP.cpp -o openmp_game

