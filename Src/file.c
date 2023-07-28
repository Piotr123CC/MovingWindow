#include "Inc/file.h"
#include "Inc/queue.h"
#include "Inc/algorithms.h"
#include "errno.h"

#define PRINTF 0 //set to 1 if you want print data

/**
 * @brief This function creates a .csv file with random data
 * 
 * @param name 
 * @param dataLength 
 * @return fileState_t 
 */
fileState_t generateRandomData(const char *name, size_t dataLength)
{
    FILE *fp = NULL;
    fp = fopen(name,"w+");
    if (fp != NULL)
    {
#if PRINTF
        printf("File created successfully\n");
#endif
    }
    else
    {
        perror("Creating file error");
        return fileError;
    }
    
    for (size_t i =0 ;i<dataLength/4;i++)
    {
        float data = ((float)rand()/RAND_MAX)*20;
        fprintf(fp,"%.2f;\n",data);
    }


    for (size_t i =0 ;i<dataLength/4;i++)
    {
        float data = ((float)rand()/RAND_MAX)*30+20;
        fprintf(fp,"%.2f;\n",data);
    }

    for (size_t i =0 ;i<dataLength/4;i++)
    {
        float data = ((float)rand()/RAND_MAX)*30+40;
        fprintf(fp,"%.2f;\n",data);
    }

    for (size_t i =0 ;i<dataLength/4;i++)
    {
        float data = ((float)rand()/RAND_MAX)*20+10;
        fprintf(fp,"%.2f;\n",data);
    }
    fclose(fp);
    fp = NULL;

    return fileOK;
}


/**
 * @brief This function reads .csv file with raw data
 *        then processes and puts into file with name "FilteredData.csv"
 * 
 * @param name 
 * @return fileState_t 
 */
fileState_t handleData(const char *name)
{
    FILE *inputFile = NULL;
    FILE *outputFile = NULL;
    
    if (openFiles(name, &inputFile, &outputFile) != fileOK)
    {
        return fileError;
    }
    
    outputData_t outputData;
    queue_t buf;
    queueInit(&buf);
    
#if PRINTF
    printf("in\tAvg\tMax\tMin\n"); 
#endif
    fprintf(outputFile,"In;\tAvg;\tMax;\tMin;\n");

    while (fscanf(inputFile,"%f;",&outputData.dataIn) != -1)
    {
        if (processData(&buf,outputFile,&outputData) != fileOK)
        {
            return fileError;
        }
        
    }

    if (closeFiles(&inputFile,&outputFile) != fileOK)
    {
        return fileError;
    }
    
    return fileOK;
}

/**
 * @brief This function opens and checks if files were opened properly
 * 
 * @param name 
 * @param inputFile 
 * @param outputFile 
 * @return fileState_t 
 */
fileState_t openFiles(const char *name,FILE **inputFile, FILE **outputFile)
{
    *inputFile = fopen(name,"r");
    if (*inputFile != NULL)
    {
#if PRINTF
        printf("File opened successfully\n");
#endif
    }
    else
    { 
        perror("File opening error");

        return fileError;
    }

    *outputFile = fopen("FilteredData.csv","a+");

    if (*outputFile != NULL)
    {
#if PRINTF
        printf("File with filtered data created successfully \n");
#endif
    }
    else
    {
        if (fclose(*outputFile) == 1)
        {
            perror("File closing error");
        }
        inputFile = NULL;

        return fileError;
    }

    return fileOK;
}

/**
 * @brief This function closes and checks if files were closed properly 
 * 
 * @param inputFile 
 * @param outputFile 
 * @return fileState_t 
 */
fileState_t closeFiles(FILE **inputFile, FILE **outputFile)
{
    if (fclose(*inputFile) == 1)
    {
        perror("Closing error input file");
        return fileError;
    }
    *inputFile = NULL;

    if (fclose(*outputFile) == 1)
    {
        perror("Closing error output file");
        return fileError;
    }
    *outputFile=NULL;
    return fileOK;
}

/**
 * @brief This function takes the read data and processess it
 * 
 * @param buf 
 * @param outputFile 
 * @param outputData 
 * @return fileState_t 
 */
fileState_t processData(queue_t *buf, FILE *outputFile, outputData_t *outputData)
{
    putIntoQueue(buf,outputData->dataIn);

    getAverage(buf, outputData); 

    getMinMax(buf,outputData);
    
#if PRINTF
        printf("%.2f\t%.2f\t%.2f\t%.2f \n",outputData->dataIn, outputData->average , outputData->max, outputData->min);
#endif
    fprintf(outputFile,"%.2f;\t%.2f;\t%.2f;\t%.2f;\n",outputData->dataIn, outputData->average,
                                                        outputData->max, outputData->min);
    if(ferror(outputFile))
    {
        perror("Writing file error");
        return fileError;
    }
    return fileOK;
}