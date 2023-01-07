/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 */

#include <stdio.h>

// @lc code=start
int maxArea(int* height, int n){
  int left = 0, right = n - 1;
  int max_area = 0;
  while (left < right) {
    int area = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
    if (area > max_area) max_area = area;
    if (height[left] < height[right]) {
      int i = left;
      while (i < right && height[i] <= height[left]) i++;
      left = i;
    } else {
      int i = right;
      while (i > left && height[i] <= height[right]) i--;
      right = i;
    }
  }

  return max_area;
}
// @lc code=end

