/*
 * @lc app=leetcode id=12 lang=c
 *
 * [12] Integer to Roman
 */

#include <stdio.h>
#include <string.h>

// @lc code=start
char *intToRoman(int num)
{
  static char *roman[4][10] = {
      {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
      {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
      {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
      {"", "M", "MM", "MMM"}};
  static char result[16];
  memset(result, 0, sizeof(result));
  int index = 0;
  for (int i = 3; i >= 0; i--)
  {
    int digit = num / (int)pow(10, i) % 10;
    if (digit)
    {
      strcat(result, roman[i][digit]);
    }
  }

  return result;
}
// @lc code=end
