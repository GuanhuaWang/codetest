#include <stdio.h>  
#include <stdlib.h>  
#include <omp.h>  
#include <memory.h>  
#include <unistd.h> 

void bestSubSeq_OpenMP(int *candyArray, int home, int target)
{
	int numThreads = 0;
	#pragma omp parallel
	{
		numThreads = omp_get_num_threads();
	}

	if(numThreads > home)
	{
		omp_set_num_threads(home);
		numThreads = home;
	}

	int *subLargestSum = (int*)malloc(home*sizeof(int));
	int *subLargestStart = (int*)malloc(home*sizeof(int));
	int *subLargestEnd = (int*)malloc(home*sizeof(int));
	bool *finish = (bool*)malloc(home*sizeof(bool));

	memset(finish,true,home);
	int subSize = (home + numThreads-1)/numThreads;	

	#pragma omp parallel
	{
		for(int i =0; i<subSize;i++)
		{
			int threadId = omp_get_thread_num();
			int currentId = threadId*subSize+i;
			if(currentId < home)
			{
				subLargestSum[currentId] = -1;
				subLargestStart[currentId] = -1;
				subLargestEnd[currentId] = -1;
	
				int start = currentId;
				int end = start;
  
				int currentSum = candyArray[currentId];
				bool finishFlag = finish[currentId];

				while(finishFlag)
				{

					if(currentSum > subLargestSum[currentId] && currentSum <= target)
					{
						subLargestSum[currentId] = currentSum;
						subLargestStart[currentId] = start;
						subLargestEnd[currentId] = end;

						if(subLargestSum[currentId] == target)
						{
							for(int i = currentId;i<threadId*(subSize+1);i++)
							{
								finish[i] = false;
							}
							finishFlag = false;
							continue;
						}
					}

					if((end == home - 1 && currentSum <= target) || (start == home - 1 && end == home - 1))
					{
						finish[currentId] = false;
						finishFlag = false;
					}
			
                	if(currentSum > target)
                	{ 
                    	finish[currentId] = false;
                    	finishFlag = false;
                	}
                	else
                	{
                    	end = end + 1;
                    	currentSum += candyArray[end];
                	}

				}
			}	
		}
	}

	int largestSum = -1;
	int id = -1;

	for(int i = 0; i < home; i++)
	{
		if(largestSum < subLargestSum[i])
		{
			largestSum = subLargestSum[i];
			id = i;
		}
	}

	if(largestSum == -1)
		printf("Don't go here\n");
	else
		printf("Start at home %d and go to home %d getting %d pieces of candy\n",subLargestStart[id] + 1,subLargestEnd[id] + 1,largestSum);

}

int main(int argc, char const *argv[])
{
	//set number of threads to use
	omp_set_num_threads(3);

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

		bestSubSeq_OpenMP(candyArray,home,target);
		fclose(input);
		free(candyArray);
	}
	else
	{
		printf("File cannot be opened");
	}
	return 0;
}
