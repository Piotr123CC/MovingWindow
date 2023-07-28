#include "stdio.h"
#include "stdlib.h"
#include "Inc/file.h"
#include "string.h"


int main(int argc, char *argv[])
{
    if (argc == 2)
    {   
        if (handleData(argv[1]) != fileOK)
        {
            exit(1);
        }
    }
    else{
        char fileName[20];
        printf("Give file name without file extension(.csv): ");
        scanf("%s",fileName);
        strcat(fileName,".csv");
        if (handleData(fileName) != fileOK)
        {
            exit(1);
        }
    }
    printf("FilteredData.csv created successfully\n");
    return 0;
}
