#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

/**
THIS FUNCTION IS PROVIDED AS PART OF THE STARTER CODE.
DO NOT MODIFY THIS FUNCTION. 
*/
std::string ConvertFloatToStr(float n, int precision) {
  std::stringstream ss; 
  ss << std::fixed << std::setprecision(precision) << n; 
  return ss.str();
}

/**
PSEUDOCODE: 

algorithm ApproxSqrt
  Input: 9 or any other number desired by usera along with iterations.
  Output: 2.25000 or other squared root number.

  Your pseudocode goes here.
    float low = 0
    float high = number passed
    float mid = 0
    float temp = 0
    for integer = 0 and integer less than iterations:
      mid = (low + high) / 2
      temp = (high * high)
      if temp is greater number passed:
       high = mid
      if temperature is less than number passed:
       low = mid
    return ConvertFloatToStr(mid, 5)

COMMENTS:
Need multiple variables to start off all of which are float types. Initiate variables to
 zero and then start a loop to start executing and comparing. For loop will be used
 as first guess will be halfway between. The number is then squared to see if it is
 higher than the number being passed. I will need to change the bounds if so. If it
 is less than I need to change lower bounds. Once root is found it is returned just
 as the number only.
*/
std::string ApproxSqrt(int n, int iterations) {
  // Implement this function.
  // You may call ConvertFloatToStr as part of your solution.
    
    float low = 0, high = n, mid = 0, temp = 0;
    
    for (int i = 0; i < iterations; i++){
        mid = (low + high) / 2;
        temp = (high * high);
        if (temp > n)
            high = mid;
        if (temp < n)
            low = mid;
    }
  return ConvertFloatToStr(mid, 5);
}

