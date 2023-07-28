#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "stdio.h"
#include "stdbool.h"


#define WINDOW_SIZE  500


typedef struct
{
    float buffer[WINDOW_SIZE];
    float actualSum;
    int head, bufferSize;

}queue_t;

void queueInit(queue_t *buffer);

void putIntoQueue(queue_t *buffer, float data);


#endif