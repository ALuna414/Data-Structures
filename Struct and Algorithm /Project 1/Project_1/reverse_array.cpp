/**
PSEUDOCODE: 

algorithm ReverseArray
  Input: [3, 4, 7, 6, 1] or another array filled with numbers
  Output: [1, 6, 7, 4, 3] or reversed version of array inputted
  Side Effect: The time compexity of the function.

  Your pseudocode goes here.
    int temp
    int i
    for i equal to 0; i less than length; i plus 1:
     temp = arr[index]
     arr[index] = arr[length - index - 1]
     arr[length - index - i] = temp

COMMENTS:
Going back to CSII we would see and have to do this quite a bit so I took a
 stroll back memory lane and remembered I would have to declare an int of
 temp to temporarily hold a value and an int of I for the for loop needed to
 execute this. In the for loop condition I would have to divide the length by 2.
 Then being executed I would have to store the number in the array position
 into temp then assign the current index of the array number to the end. Then
 that number is now the temp value and the for loop will execute two more times
 so it keeps the middel value the same and swaps the right two numbers with
 the back two.
*/
void ReverseArray(int arr[], int length) {
  // Implement this function.
    int temp, i;
    
    for (i = 0; i < length/2; i++){
        temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}
