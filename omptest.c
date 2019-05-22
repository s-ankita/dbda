#include<stdio.h>
#include<omp.h>
int main()
{
	printf("Hello Thread %d",omp_get_thread_num());
	
	int a[20], i;

	/*
		Each thread will have 4 iterations to execute
	*/

	#pragma omp parallel num_threads(5)
	{
		#pragma omp for schedule(static,4)
		for (i=0 ; i<20 ; i++)
		{
			a[i] = i+10;
			//printf("\n %d  =  T %d",i, omp_get_thread_num());
		}
	}
	/*
	 	Master thread printing the array
	*/
	#pragma omp master
	for (i=0 ; i<20 ; i++)
       	{
	       	printf("\n %d",a[i]);
        }

}
