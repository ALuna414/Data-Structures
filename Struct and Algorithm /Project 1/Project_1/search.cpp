/**
PSEUDOCODE: 

algorithm LinearSearch
  Input: [1, 5, 6, 8, 9, 10, 23, 42, 59, 73, 105] or any other numbers in an array.
  Output: 7 or any other index value for that of the number being searched.

  Your pseudocode goes here.
    int i
    for i equal to 0; i less than length; i plus 1:
      if numbers array of i equals number being searched:
         return index of number found
      return -1 if number not found
 
COMMENTS:
Started off with declaring an interger that is going to be used in the for loop. I could of
 declared it in the for loop but decided to put it on the outside. This then leads to the
 for loop I have to implement in order to search for the desired number asked by the
 user. Nested in the for loop I put an if statement so once the number is found, it will
 return the index at which that number is at.
*/
int LinearSearch(int numbers[], int length, int n) {
  // Implement this function.
    for (int i = 0; i < length; i++) {
        if (numbers[i] == n)
            return i;
    }
    return -1;
}

/**
PSEUDOCODE: 

algorithm BinarySearch
  Input: [1, 5, 6, 8, 9, 10, 23, 42, 59, 73, 105] or any other numbers in an array.
  Output: 7 or any other index value for that of the number being searched.

  Your pseudocode goes here.
    int low = 0
    int mid
    int high = length -1
    while high is greater or equal too low:
      mid = (high + low) / 2
      if numbers[mid] is less than n:
        low = mid + 1
      else if numbers[mid] greater than n:
        high = mid - 1
      else:
        return mid
    return -1 if number not found

COMMENTS:
Started off by declaring three integersfor the lowest value, middle value,
 and highest value. I had to set lowest equal to zero and the highest
 equal to the length minus one. The middle is needed to be calculated
 by dividing the length in half to get the index. A while loop is needed
 with nested if and else if statements. Once the index is found it is
 returned.
*/
int BinarySearch(int numbers[], int length, int n) {
  // Implement this function.
    int low = 0;
    int mid;
    int high = length-1;
    
    while (high >= low) {
        mid = (high + low) / 2;
        
        if (numbers[mid] < n) {
           low = mid + 1;
        }
        else if (numbers[mid] > n) {
           high = mid - 1;
        }
        else {
           return mid;
        }
    }
  return -1;
}
