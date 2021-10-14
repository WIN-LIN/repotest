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
        MergeSort(array,size);

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

// Function to Merge Arrays L and R into A. 
// lefCount = number of elements in L
// rightCount = number of elements in R. 
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
        int i,j,k;

            // i - to mark the index of left aubarray (L)
            // j - to mark the index of right sub-raay (R)
            // k - to mark the index of merged subarray (A)
            i = 0; j = 0; k =0;

                while(i<leftCount && j< rightCount) {
                            if(L[i]  < R[j]) A[k++] = L[i++];
                                    else A[k++] = R[j++];
                                        }
                    while(i < leftCount) A[k++] = L[i++];
                        while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void MergeSort(int *A,int n) {
        int mid,i, *L, *R;
            if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

                mid = n/2;  // find the mid index. 

                    // create left and right subarrays
                    // mid elements (from index 0 till mid-1) should be part of left sub-array 
                    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
                    L = (int*)malloc(mid*sizeof(int)); 
                        R = (int*)malloc((n- mid)*sizeof(int)); 
                            
                            for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
                                for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

                                    MergeSort(L,mid);  // sorting the left subarray
                                        MergeSort(R,n-mid);  // sorting the right subarray
                                            Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
                                                    free(L);
                                                            free(R);
}
