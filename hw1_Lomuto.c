#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void Merge(int *A,int *L,int leftCount,int *R,int rightCount);
void MergeSort(int *A,int n);
int main () {
    double avg_time = 0;
    for(int test = 0; test < 10;test++){
        
        //Randomized array
        int size = pow(2,21);
        int array[size];
        for (int i = 0; i < size; i++) {
            array[i] = rand()%1000;
        }

        //Start measuring time
        clock_t start = clock(); 
        
        //Sorting

        // Stop measuring time and calculate the elapsed time
        clock_t end = clock();
        double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
        printf("Time measured: %.3f seconds.\n",elapsed);
        avg_time += elapsed; 
        /*for(int i=0;i<size;i++){
            printf("%d\n",array[i]);
        } */                           
        
    }
    printf("Avg time: %.3f sec.",avg_time/10);

    return 0;
}    
