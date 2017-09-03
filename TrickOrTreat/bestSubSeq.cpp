#include <stdlib.h>
#include <stdio.h>

void bestSubSeq(int* candyArray, int home, int target)
{
	int largestCandySum = -1;
	int largestStart = -1;
	int largestEnd = -1;

	int currentSum = candyArray[0];
	int start = 0;
	int end = 0;

	bool endFlag = true;

	while(endFlag)
	{
		if(currentSum < target)
			{
				end = end + 1;
				currentSum += candyArray[end];
				if (currentSum == target)
				{
					endFlag = false;
				}
			}
		else
			{
				start = start + 1;
				currentSum -= candyArray[start - 1];
				if(start > end)
				{
					end = end + 1;
					currentSum = candyArray[start];
				}
			}

		if(currentSum > largestCandySum && currentSum <= target)
		{
			largestCandySum = currentSum;
			largestStart = start;
			largestEnd = end;
			if(largestCandySum == target)
			{
				endFlag = false;
			}
		}

		if((end == home - 1 && currentSum <= target)||(start == home - 1 && end == home - 1))
		{
			endFlag = false;
		}
	}

	if(largestCandySum == -1) printf("Don't go here\n");
	else printf("Start at home %d and go to home %d getting %d pieces of candy\n",largestStart + 1, largestEnd + 1,largestCandySum);

}


int main(int argc, char const *argv[])
{
	int home = 0;
	int target = 0;
	int *candyArray = NULL; 

	FILE *input;
	if((input = fopen("input.txt","r")))
	{
		fscanf(input,"%d",&home);
		fscanf(input,"%d",&target);
		if((candyArray = (int *)malloc(home*sizeof(int))) == NULL)  
        {  
            printf("memory allocation failed, exit\n");  
            exit(1);  
        }

		for(int i =0;i<home;i++)
		{
			fscanf(input,"%d",&candyArray[i]);
		}

		bestSubSeq(candyArray,home,target);
		fclose(input);
		free(candyArray);
	}
	else
	{
		printf("File cannot be opened");
	}

	return 0;
}