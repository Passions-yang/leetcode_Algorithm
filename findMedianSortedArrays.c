#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * Merge_sort(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int * p = NULL,*arry = NULL;
    int i = 0,j =0,k = 0;
    if(!(nums1 || nums2)) return NULL;
    arry = p = (int *)malloc(sizeof(int)*(nums1Size + nums2Size + 1));
    memset(arry,0x00,nums1Size + nums2Size);
    while(i < nums1Size && j < nums2Size){
        if(nums1[i] < nums2[j])
            p[k++] = nums1[i++];
        else
            p[k++] = nums2[j++];
    }
    while(i < nums1Size){
        p[k++] = nums1[i++];
    }
    while(j < nums2Size){
        p[k++] = nums2[j++];
    }
    return arry;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
   int med = 0,total = 0;
   int * arry = NULL;
   double val = 0;
   if(!(nums1 || nums2)) return 0;
   arry = Merge_sort(nums1,nums1Size,nums2,nums2Size);
   total = nums1Size + nums2Size;
   med = total >> 1;
   if(total % 2){
        val = arry[med];
   }else{
        val = ((double)(arry[med] + arry[med -1]))/2.0;
   }
   free(arry);
   return val;
}


int main(int argc,char *argv[])
{
    int nums1[4] = {2,3,4,5};
    int nums2[] = {};
    double val = findMedianSortedArrays(nums1,4,nums2,0);
    printf("med : %f\n",val);


    return 0;
}




