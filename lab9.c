#include <stdio.h>
#include <stdlib.h>


struct RecordType
{
	int		id;
	char	name;
	int		order; 
};


struct HashType
{
	struct RecordType* data;
	int size; 
};


int hash(int x, int size)
{
	return x % size;
}


int parseData(char* inputFileName, struct RecordType** ppData)
{
FILE* inFile = fopen(inputFileName, "r");
	int dataSz = 0;
	int i, n;
	char c;
	struct RecordType *pRecord;
	*ppData = NULL;

	if (inFile)
}


void printRecords(struct RecordType pData[], int dataSz)
{
int i;
	printf("\nRecords:\n");
	for (i = 0; i < dataSz; ++i)
	{
		printf("\t%d %c %d\n", pData[i].id, pData[i].name, pData[i].order);
	}
	printf("\n\n");
}


void displayRecordsInHash(struct HashType *pHashArray, int hashSz)
{
	int i;
	struct RecordType* pData;

	for (i = 0; i < hashSz; ++i)
	{
		pData = (pHashArray + i)->data;
		if (pData != NULL)
		{
			printf("Index %d -> ", i);
			while (pData->id != -1) // Assuming -1 is an invalid ID (you can change this accordingly)
			{
				printf("%d %c %d -> ", pData->id, pData->name, pData->order);
				pData++;
			}
			printf("NULL\n");
		}
	}
}

int main(void)
{
	struct RecordType *pRecords;
	int recordSz = 0;

	recordSz = parseData("input.txt", &pRecords);
	printRecords(pRecords, recordSz);
	// Your hash implementation
}
