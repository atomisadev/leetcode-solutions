/*
 * @lc app=leetcode id=10 lang=c
 *
 * [10] Regular Expression Matching
 */

#include <stdbool.h>
#include <string.h>

// @lc code=start
bool isMatch(char * s, char * p){
  if (*p == '\0') return *s == '\0';
  bool first_match = *s && (*s == *p || *p == '.');
  if (*(p + 1) == '*') {
    return isMatch(s, p + 2) || (first_match && isMatch(s + 1, p));
  } else {
    return first_match && isMatch(s + 1, p + 1);
  }
}
// @lc code=end

