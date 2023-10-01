#include <stdio.h>
#include <limits.h>

int main() {
 
   int arr[50], n, i;

   //Enter the size of an array 
   printf("Enter the size of an array (Max 50) \n");
   scanf("%d", &n);
 
   printf("Enter an array elements\n");

   //Input array values 
   for(i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   //Intialize variable with max int value 
   int smallest = INT_MAX;
   int secondSmallest = INT_MAX;

   //Traverse an array 
   for(i = 0; i < n; i++) {
  
     //If element is smaller
     if(arr[i] < smallest) {
         secondSmallest = smallest;
         smallest = arr[i];
     }
  
     if(arr[i] > smallest && arr[i] < secondSmallest) {
         secondSmallest = arr[i];
     }
  }
 
  printf("Second smallest %d", secondSmallest);
 
  return 0;
}