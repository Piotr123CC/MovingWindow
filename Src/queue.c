
#include "../Inc/queue.h"

/**
 * 
 * @brief Initialization of queue
 * 
 * @param buffer 
 * @return queueState_t 
 * 
 */
void queueInit(queue_t *buffer)
{
    buffer->head = 0;
    buffer->bufferSize = 0;
    buffer->actualSum=0;
}

/**
 * @brief This function puts data into queue 
 * 
 * @param buffer 
 * @param data 
 * @return queueState_t 
 */

void putIntoQueue(queue_t *buffer,const float data)
{
    if(buffer->bufferSize == WINDOW_SIZE)
    {
        buffer->actualSum -= buffer->buffer[buffer->head];
    }
    else
    {
        buffer->bufferSize++;
    }

    buffer->actualSum += data;
    buffer->buffer[buffer->head] = data;
    buffer->head = ++(buffer->head) % WINDOW_SIZE;

}


