/*
 * project2.cpp
 * 
 * The implementation file where you will implement your code for Project 2.
 *
 * INSTRUCTOR NOTE: Do not change any of the existing function signatures in
 * this file. You may add helper functions for 
 * any function other than Sum in Question 1. 
 */

#include "recursive_list.h"
#include "project2.h"



/** QUESTION 1: SUM AND PRODUCT **/

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// Your implementation of Sum should NOT be tail recursive and should NOT
// use a helper function. 
//
// PSEUDOCODE:
// algorithm Sum
//   check if list is empty
//     return 0
//   else
//   return ListFirst(list) + Sum(ListRest(list));
//
// COMMENTS:
// Going into this one I looked in the class notes to see the SumToN part.
// It is very similar since i am looking for the sum. I have to use different
// variables however and return is along same concept.
int Sum(RecursiveList list) {
  // Implement this function.
    if(ListIsEmpty(list))
        return 0;
    else
        return ListFirst(list) + Sum(ListRest(list));
}

// EFFECTS: returns the product of each element in list, or one if the list is
//          empty
//
// PSEUDOCODE:
// algorithm Product
//   check if list is empty
//     return 0
//   else
//   return ListFirst(list) + Product(ListRest(list));
//
// COMMENTS:
// This one is just like the previous as the only difference is I am finding the
// product now. I came at it by following the code from the previous one and just
// modifying it.
int Product(RecursiveList list) {
  // Implement this function.
    if(ListIsEmpty(list))
        return 0;
    else
        return ListFirst(list) + Product(ListRest(list));
}



/** QUESTION 2: TAIL RECURSIVE SUM **/

// EFFECTS: adds the next element in the list to the sum so far
// Your implementation of TailRecursiveSumHelper MUST be tail recursive.
//
// PSEUDOCODE:
// algorithm TailRecursiveSumHelper
//   check to see if the list is empty
//     return sum_so_far variable
//   else
//     sum_so_far += ListFirst(list)
//     return TailRecursiveSumHelper(ListRest(list), sum_so_far)
//
// COMMENTS:
// This is going to be a tail recursive function. It is stated in the
// algorithm for what variables needs to come in. I am just writing the
// helper function so as before I knew I needed an if statement to check is
// list is empty. Then after that I'm going to call the Recursive helper
// algorithm again with different variables being called through.
int TailRecursiveSumHelper(RecursiveList list, int sum_so_far) {
  // Implement this function.
    if(ListIsEmpty(list))
        return sum_so_far;
    else {
        sum_so_far += ListFirst(list);
        return TailRecursiveSumHelper(ListRest(list), sum_so_far);
    }
}

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// THIS FUNCTION IS PROVIDED AS PART OF THE STARTER CODE.
// DO NOT MODIFY THIS FUNCTION.
// 
// PSEUDOCODE:
// algorithm TailRecursiveSum
//   return TailRecursiveSumHelper(list, 0)
int TailRecursiveSum(RecursiveList list) {
  return TailRecursiveSumHelper(list, 0);
}



/** QUESTION 3: FILTER ODD AND FILTER EVEN **/

// EFFECTS: returns a new list containing only the elements of the original list
//          which are odd in value, in the order in which they appeared in list
// For example, FilterOdd(( 4 1 3 0 )) would return the list ( 1 3 )
//
// PSEUDOCODE:
// algorithm FilterOdd
//   RecursiveList OddFiltred = Makelist()
//   return FilterOddHelper
// algorithm FilterOddHelper
//   check if list is empty
//     return total
//   else
//      if not ListFirst module 2
//          return FilterOddHelper
//      else
//          return FilterOddHelper(ListRest, MakeList, total)
//
// COMMENTS:
// Going into this one I knew I was going to need a helper function. The
// helper function will do all the work in which I will first check to see
// if the list is empty. If it isn't then I'm going to find the numbers in
// the list that are odd and recursively call it. then once the total of
// numbers found that are odd, I will go back into FilterOdd and return the
// helper funcion with list and MakeList variables.
RecursiveList FilterOddHelper(RecursiveList list, RecursiveList total) {
    if(ListIsEmpty(list))
        return total;
    else {
        if(!(ListFirst(list)%2))
            return FilterOddHelper(ListRest(list), total);
        else
            return FilterOddHelper(ListRest(list), MakeList(ListFirst(list), total));
    }
}
RecursiveList FilterOdd(RecursiveList list) {
  // Implement this function.
    RecursiveList OddFiltered = MakeList();
  return FilterOddHelper(list, OddFiltered);
}

// EFFECTS: returns a new list containing only the elements of the original list
//          which are even in value, in the order in which they appeared in list
// For example, FilterEven(( 4 1 3 0 )) would return the list ( 4 0 )
//
// PSEUDOCODE:
// algorithm FilterEven
//   RecursiveList EvenFiltred = Makelist()
//   return FilterEvenHelper
// algorithm FilterEvenHelper
//   check if list is empty
//     return total
//   else
//      if ListFirst module 2
//          return FilterEvenHelper
//      else
//          return FilterEvenHelper(ListRest, MakeList, total)
//
// COMMENTS:
// This one is going to be similar as the previous one as the only difference
// now is that I am trying to filter the even numbers. Still have a helper that
// does the same as above.
RecursiveList FilterEvenHelper(RecursiveList list, RecursiveList total) {
    if(ListIsEmpty(list))
        return total;
    else {
        if(ListFirst(list)%2)
            return FilterEvenHelper(ListRest(list), total);
        else
            return FilterEvenHelper(ListRest(list), MakeList(ListFirst(list), total));
    }
}
RecursiveList FilterEven(RecursiveList list) {
  // Implement this function.
    RecursiveList EvenFiltered = MakeList();
  return FilterEvenHelper(list, EvenFiltered);
}
    
    

/** QUESTION 4: REVERSE **/

// EFFECTS: returns the reverse of list
// For example, the reverse of ( 3 2 1 ) is ( 1 2 3 )
//
// PSEUDOCODE:
// algorithm ReverseHelper
//   check if list is empty
//     return Reverse
//   if not
//     return ReverseHelper
//  algorithm Reverse
//   RecursiveList ReverseList = MakeList()
//   return ReverseHelper(list, ReverseList)
//
// COMMENTS:
// Having to reverse numbers around seems simple but I struggled
// with this one. I decided to go with another helper function addition
// as it would save me time and brain stress. The helper function will
// take ListRest, MakeList, and use reverse call to function.
RecursiveList ReverseHelper(RecursiveList list, RecursiveList Reverse) {
    if (ListIsEmpty(list))
        return Reverse;
    else
        return ReverseHelper(ListRest(list), MakeList(ListFirst(list), Reverse));
}
RecursiveList Reverse(RecursiveList list) {
  // Implement this function.
    RecursiveList ReverseList = MakeList();
  return ReverseHelper(list, ReverseList);
}



/** QUESTION 5: APPEND **/

// EFFECTS: returns the list (first_list second_list)
// For example, if first_list is ( 1 2 3 ) and second_list is ( 4 5 6 ), then
// returns ( 1 2 3 4 5 6 )
//
// PSEUDOCODE:
// algorithm AppendHelper
//  check if list is empty
//      return MakeList()
//  else if List is empty with first list
//      return second_list
//  else if List is empty with second list
//      return first_list
//  else
//      if list is empty call with reverse first
//          return total
//      else
//          return AppendHelper
// algorithm Append
//  return AppendHelper ()
//
// COMMENTS:
// Thinking recursively on this I knew I was going to have to follow the
// recursive tips from the powerpoint slides. I wrote the pseudocode first
// to help get the ideas of how to come into it onto code. I knew I had to check
// if list was empty. If so then I mad another, and then used if conditions to
// transfer first empty list into secodn and second into first. The return
// would involve the first and second lists with MakeList and ListRest I beleive.
RecursiveList AppendHelper(RecursiveList first_list, RecursiveList second_list, RecursiveList             reverse_first, RecursiveList total) {
    if(ListIsEmpty(first_list) && ListIsEmpty(second_list))
        return MakeList();
    else if(ListIsEmpty(first_list))
        return second_list;
    else if(ListIsEmpty(second_list))
        return first_list;
    else {
        if(ListIsEmpty(reverse_first))
            return total;
        else
            return AppendHelper(first_list, second_list, ListRest(reverse_first), MakeList(ListFirst(reverse_first), total));
        }
}
RecursiveList Append(RecursiveList first_list, RecursiveList second_list) {
  // Implement this function.
  return AppendHelper(first_list, second_list, Reverse(first_list), second_list);
}


    
/** QUESTION 6: CHOP **/

// REQUIRES: list has at least n elements
// EFFECTS: returns the list equal to list without its last n elements
//
// PSEUDOCODE:
// algorithm ChopHelper
//  if list is empty then
//      return list
//  return ChopHelper
// algorithm Chop
//  return (ChopHelper(reverse(list),n))
//
// COMMENTS:
// Another function in which I used a helper. Just like the rest so far, I have
// to check if list is empty and if so then I reverse it. Once the condition is checked
// then the return function does all the work. Then after the helper the main chop
// just has a return in which I return ChopHelper but with a reverse.
RecursiveList ChopHelper(RecursiveList list, unsigned int n) {
    if(ListIsEmpty(list) || n==0)
        return Reverse(list);
    return ChopHelper(RecursiveList(list), n-1);
}
RecursiveList Chop(RecursiveList list, unsigned int n) {
  // Implement this function.
  return (ChopHelper(Reverse(list), n));
}



/** QUESTION 7: ROTATE **/

// EFFECTS: returns a list equal to the original list with the
//          first element moved to the end of the list n times.
// For example, Rotate(( 1 2 3 4 5 ), 2) yields ( 3 4 5 1 2 )
//
// PSEUDOCODE:
// algorithm Rotate
//   if int passed is zero or List is empty
//      return list
//   set list equal to reverse(Makelist() and reverse Listrest
//  return RotateHelper(list, n)
//
// COMMENTS:
// This one is pretty straight forward as a list will be modified depending on
// what the user wants. I knew for this one I wanted a helper function as well.
// I started off by having same condition as others to start which is checking the
// list first. From here i ran into a brain fart so I went to slack for some
// tips. Thankfully a student helped me and made what I was thinning of how it
// should run in my head to onto the xcode. I assigned list to reverse twice and then
// in the return I decremented. Main function just has a return of the helper.
RecursiveList RotateHelper(RecursiveList list, unsigned int n) {
    if(n == 0 || ListIsEmpty(list))
        return list;
    list = Reverse(MakeList(ListFirst(list), Reverse(ListRest(list))));
    return RotateHelper(list, n - 1);
}
RecursiveList Rotate(RecursiveList list, unsigned int n) {
  // Implement this function.
  return RotateHelper(list, n);
}


    
    
/** QUESTION 8: INSERT LIST **/

// REQUIRES: n <= the number of elements in first_list
// EFFECTS: returns a list comprising the first n elements of first_list,
//          followed by all elements of second_list, followed by any remaining
//          elements of "first_list"
// For example, InsertList (( 1 2 3 ), ( 4 5 6 ), 2) returns ( 1 2 4 5 6 3 )
//
// PSEUDOCODE:
// algorithm InsertListHelper()
//  if n is sequal to 0
//    result = Append(result, second_list)
//    result = Append(result, first_list)
//    return result;
//  else
//    n--;
//    result = MakeList(ListFirst(first_list), result)
//    return InsertListHelper(ListRest(first_list), second_list, result, n)
// algorithm InsertList()
//   if ListIsEmpty(first_list) is false and ListIsEmpty(second_list) is false and n isn't 0)
//      RecursiveList result = MakeList()
//      return InsertListHelper(first_list, second_list, result, n)
//   else
//      return Append(first_list, second_list)
//
// COMMENTS:
// This is by far the hardest one yet as having to insert a list into a certain position
// on the previous list. As usual i did it with a helper function. Im going to have a lot
// of passing variables since this one requires multiple actions to be done. I decided to start
// in the helper function with the condition I have used every time about but now I added some
// more conditions to add on with. I will be calling append in this since the actions of that
// are similar to what I have to do here. Returning functions with many steps is also going to
// have to be done. A reversal might even be implemented since depending on where something is
// getting inserted it will require that. 
RecursiveList InsertListHelper(RecursiveList first_list, RecursiveList second_list, RecursiveList result, unsigned int n) {
    if(n == 0) {
        result = Append(result, second_list);
        result = Append(result, first_list);
        return result;
    }
    else {
        n--;
        result = MakeList(ListFirst(first_list), result);
        return InsertListHelper(ListRest(first_list), second_list, result, n);
    }
}


RecursiveList InsertList(RecursiveList first_list, RecursiveList second_list,
                         unsigned int n) {
  // Implement this function.
    if (ListIsEmpty(first_list) == false && ListIsEmpty(second_list) == false && n != 0) {
        RecursiveList result = MakeList();
        return InsertListHelper(first_list, second_list, result, n);
    }
    else
        return Append(first_list, second_list);
}
