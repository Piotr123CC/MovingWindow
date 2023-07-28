#ifndef _FILE_H_
#define _FILE_H_
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "queue.h"



typedef enum{
    fileOK      =   0,
    fileError   =   1
}fileState_t;

typedef struct{
    float dataIn;
    float min;
    float max;
    float average;
}outputData_t;


fileState_t generateRandomData(const char *name, size_t dataLength);

fileState_t handleData(const char *name);

fileState_t openFiles(const char *name, FILE **inputFile, FILE **outputFile);
fileState_t closeFiles(FILE **inputFile, FILE **outputFile);

fileState_t processData(queue_t *buf, FILE *outputFile, outputData_t *outputData);

#endif