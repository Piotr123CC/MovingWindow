#include "Inc/algorithms.h"

/**
 * @brief This function simply calculates average from given data
 * 
 * @param data 
 * @param outputData 
 */
void getAverage(queue_t *data, outputData_t *outputData)
{
    outputData->average = data->actualSum/data->bufferSize;
}


/**
 * @brief This function determines max and min value in given window
 * 
 * @param data 
 * @param outputData 
 */
void getMinMax(queue_t *data, outputData_t *outputData)
{
    outputData->max = data->buffer[0];
    outputData->min = data->buffer[0];
    for (int i = 0;i<data->bufferSize;i++)
    {
        if (data->buffer[i] > outputData->max)
        {
            outputData->max = data->buffer[i];
        }

        if (data->buffer[i] < outputData->min)
        {
            outputData->min = data->buffer[i];
        }
    }
}
