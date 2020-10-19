//
//  defines.h
//  PA_Project
//
//  Created by Bogdan Iovan on 19/10/2020.
//

#ifndef defines_h
#define defines_h

#define INPUT_FILE_PATH "/Users/bogdan/PA_Project/PA_Project/input.txt"
#define OUTPUT_SERIAL_FILE_PATH "/Users/bogdan/PA_Project/PA_Project/output_serial.txt"
#define OUTPUT_OPEN_MP_FILE_PATH "/Users/bogdan/PA_Project/PA_Project/output_open_mp.txt"

// RUNNING_MODE = -1 -> don't run any version(used for generating matrix)
// RUNNING_MODE = 0 -> run the serial version
// RUNNING_MODE = 1 -> run the open mp version
#define RUNNING_MODE 1

// REGENERATE_MATRIX = 0 -> don't
// REGENERATE_MATRIX = 1 -> do
#define REGENERATE_MATRIX 0

// Matix NxM
#define N_ROWS 256
#define M_COLUMNS 256

#define ITERATIONS 500

#endif /* defines_h */
