//Caitlin Wallsmith
//2.23.24
//Lab 6
#include <stdio.h>

//Write an efficient recursive function that takes in a sorted array of numbers, two integers, low and high, representing indexes into the array, and another integer, value, and returns the index in the array where value is found in the array in between index low and high, inclusive. If value is NOT found in the array in between indexes low and high, inclusive, then the function should return -1.
int search(int numbers[], int low, int high, int value) 
{
  //if value is not found in the array return -1.
  if (low > high) 
  {
    return -1;
  }
  //get middle index
  int mid = (low + high) / 2;
  //if value is found in the middle index
  if (numbers[mid] == value) {
    return mid;
  }
  //if middle index is less than value have the function search the right side of the array
  else if (numbers[mid] < value) {
    return search(numbers, mid + 1, high, value);
  }
  //if not, search left side of array
  else {
    return search(numbers, low, mid - 1, value);
  }
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}