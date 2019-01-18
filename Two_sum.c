#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0,j = 0;
    int * index = NULL;
    if(NULL == nums) return NULL;
    index = (int *)malloc(2* sizeof(int));
    for(i = 0;i < numsSize;++i){
        for(j = numsSize - 1;j > i; --j){
            if(target == (nums[i] + nums[j])){
                index[0] = i + 1,index[1] = j +1;
                goto end;
            }
        }
    }
end:
    return index;
}

int main(int argc,char *argv[])
{
    int nums[] = {4,5,6,8,9,12,45,36};
    int *value = NULL;
    int nums_size = sizeof(nums)/sizeof(int);
    value = twoSum(nums, nums_size, 18);
    printf("index:[%d:%d]\n",*value,*(value+1));
    return 0;
}
