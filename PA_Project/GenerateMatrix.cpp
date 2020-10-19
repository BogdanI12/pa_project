//
//  GenerateMatrix.cpp
//  PA_Project
//
//  Created by Bogdan Iovan on 19/10/2020.
//

#include "defines.h"

#if REGENERATE_MATRIX == 1
#define GameOfLifeOpenMP

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
    
    cout<<"Generating matrix."<<endl;
    
    ofstream file(INPUT_FILE_PATH);
    
    file<<N_rows<<" "<<M_columns;
    file<<endl;
    
    for(int i = 1; i<N_rows - 1; i++)
    {
        for(int j = 1; j<M_columns - 1; j++)
        {
            int flag = rand() % 10;
            if(flag >= 9){
                file<<"X"<<" ";
            } else {
                file<<"."<<" ";
            }
        }
        file<<endl;
    }

    file.close();
    
    cout<<"Generation finished."<<endl;
}

#endif
