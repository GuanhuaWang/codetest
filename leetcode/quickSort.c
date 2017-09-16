#include <stdio.h>
#include <stdlib.h>

int partition(int arr[],int low,int high)
{
	int key;
	key = arr[low];
	while(low<high){
		while(low<high && arr[high]>=key)
			high--;
		if(low<high)
			arr[low] = arr[high];
		while(low<high && arr[low]<=key)
			low++;
		if(low<high)
			arr[high] = arr[low];
	}

	arr[low] = key;
	return low;
}

void quick_sort(int arr[],int start,int end){
	int pos;
	if(start<end){
		pos = partition(arr,start,end);
		quick_sort(arr,start,pos-1);
		quick_sort(arr,pos+1,end);
	}

	return;
}

int main(int argc, char const *argv[])
{
	int c[] = {3,6,2,4,7,12,5,7,2};
	quick_sort(c,0,8);
	for(int i=0;i<9;i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");

	return 0;
}

