/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 */

#include <stdio.h>
#include <string.h>

// @lc code=start
char *longestCommonPrefix(char **strs, int n)
{
  if (n == 0)
    return "";
  if (n == 1)
    return strs[0];
  static char result[128];
  memset(result, 0, sizeof(result));
  for (int i = 0; i < 128; i++)
  {
    char c = strs[0][i];
    for (int j = 1; j < n; j++)
    {
      if (strs[j][i] != c)
        return result;
    }
    result[i] = c;
  }
  return result;
}
// @lc code=end
