/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
  *returnSize = 0;                                                       // initialize the return size
  int **result = malloc(numsSize * numsSize * numsSize * sizeof(int *)); // allocate space for the result
  *returnColumnSizes = malloc((*returnSize) * sizeof(int));              // allocate space for the column sizes
  for (int i = 0; i < numsSize; i++)
  {
    for (int j = i + 1; j < numsSize; j++)
    {
      for (int k = j + 1; k < numsSize; k++)
      {
        if (nums[i] + nums[j] + nums[k] == 0)
        {                                                // if the triplet sums to 0
          result[*returnSize] = malloc(3 * sizeof(int)); // allocate space for the triplet
          result[*returnSize][0] = nums[i];
          result[*returnSize][1] = nums[j];
          result[*returnSize][2] = nums[k];
          (*returnSize)++;                                                               // increment the return size
          *returnColumnSizes = realloc(*returnColumnSizes, (*returnSize) * sizeof(int)); // reallocate space for the column sizes
          (*returnColumnSizes)[*returnSize - 1] = 3;                                     // set the column size for the triplet
        }
      }
    }
  }
  return result;
}
// @lc code=end
