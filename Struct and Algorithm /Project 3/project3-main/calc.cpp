// Run in repl.it:
// clang++-7 -pthread -std=c++17 -o calc calc.cpp; ./calc < calc_test1.in

#include <cstdlib>
#include <iostream>
#include <string>

#include "dlist.h"

/*
  operations: + add
              - subtract
              * multiply
              / divide
              n negate top item
              d duplicate top item
              r reverse top two items
              p print top item
              c clear entire stack
              a print all items
              q quit
*/

class divZero {};
class badInput {};

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/*******************************************************
 * INSTRUCTOR NOTE: Implement the functions below.     *
 * You may throw exception classes emptyList, divZero, *
 * or badInput from these functions as needed.         *
 ******************************************************/

// EFFECTS: performs + operation
void DoAdd(Dlist<double> &stack) {
  // Implement this function.
  if (!stack.IsEmpty()) {
    double result1 = stack.RemoveFront();

    if (!stack.IsEmpty()) {
      double result2 = stack.RemoveFront();
      double sum = result1;
      sum = result1 + result2;
      stack.InsertFront(sum);
      }
    else {
      stack.InsertFront(result1);
      throw emptyList();
    }
  }
    else
      throw emptyList();
}

// EFFECTS: performs - operation
void DoSub(Dlist<double> &stack) {
  // Implement this function.
   if (!stack.IsEmpty()) {
    double result1 = stack.RemoveFront();

    if (!stack.IsEmpty()) {
      double result2 = stack.RemoveFront();
      double sum = result1;
      sum = result2 - result1;
      stack.InsertFront(sum);
      }
    else {
      stack.InsertFront(result1);
      throw emptyList();
    }
  }
    else
      throw emptyList();
}

// EFFECTS: performs * operation
void DoMult(Dlist<double> &stack) {
  // Implement this function.
    if (!stack.IsEmpty()) {
    double result1 = stack.RemoveFront();

    if (!stack.IsEmpty()) {
      double result2 = stack.RemoveFront();
      double sum = result1;
      sum = result1 * result2;
      stack.InsertFront(sum);
      }
    else {
      stack.InsertFront(result1);
      throw emptyList();
    }
  }
    else
      throw emptyList();
}

// EFFECTS: performs / operation
void DoDiv(Dlist<double> &stack) {
  // Implement this function.
   if (!stack.IsEmpty()) {
    double result1 = stack.RemoveFront();

    if (!stack.IsEmpty()) {
      double result2 = stack.RemoveFront();
      double sum = result1;
      sum = result2 / result1;
      stack.InsertFront(sum);
      }
    else {
      stack.InsertFront(result1);
      throw emptyList();
    }
  }
    else
      throw emptyList();
}

// EFFECTS: performs n operation
void DoNeg(Dlist<double> &stack) {
  // Implement this function.
    int count = 0, result = 0;
    
    while (!stack.IsEmpty() && count < 1) {
        if (count < 1) {
            result = stack.RemoveFront();
            result *= -1;
            count++;
        }
    }
    
    if (count == 1)
        stack.InsertFront(result);
    else
        throw emptyList();
}

// EFFECTS: performs d operation
void DoDup(Dlist<double> &stack) {
  // Implement this function.
    int result = 0;
    
    if (!stack.IsEmpty()) {
        result = stack.RemoveFront();
        stack.InsertFront(result);
        stack.InsertFront(result);
    }
}

// EFFECTS: performs r operation
void DoRev(Dlist<double> &stack) {
  // Implement this function.
    int count = 0, result = 0, result2 = 0;
    
    while (!stack.IsEmpty() && count < 1) {
        result = stack.RemoveFront();
        result2 = stack.RemoveFront();
        count++;
    }
    
    if (count == 1) {
        stack.InsertFront(result2);
        stack.InsertFront(result);
    }
    else
        throw emptyList();
}

// EFFECTS: performs p operation
void DoPrint(Dlist<double> &stack) {
  // Implement this function.
    int count = 0, result = 0;
    
    while (!stack.IsEmpty() && count < 1) {
        result = stack.RemoveFront();
        count++;
    }
    
    if (count == 1)
        std::cout << result << std::endl;
    
    stack.InsertFront(result);
}

// EFFECTS: performs c operation
void DoClear(Dlist<double> &stack) {
  // Implement this function.
    while (!stack.IsEmpty()) {
        stack.RemoveFront();
    }
}

// EFFECTS: performs a operation
void DoPrintAll(Dlist<double> &stack) {
  // Implement this function.
    while(stack.IsEmpty() == false) {
      double n = stack.RemoveFront();
      std::cout << n;
      stack.InsertBack(n);
    }
 }


/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

bool DoOne(Dlist<double> &stack) {
  std::string s;
  double d;

  std::cin >> s;
  switch (s[0]) {
  case '+':
    DoAdd(stack);
    break;
  case '-':
    DoSub(stack);
    break;
  case '*':
    DoMult(stack);
    break;
  case '/':
    DoDiv(stack);
    break;
  case 'n':
    DoNeg(stack);
    break;
  case 'd':
      DoDup(stack);
      break;
  case 'r':
      DoRev(stack);
      break;
  case 'p':
      DoPrint(stack);
      break;
  case 'c':
      DoClear(stack);
      break;
  case 'a':
      DoPrintAll(stack);
      break;
  case 'q':
      return true;
      break;
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
      d = std::atof(s.c_str());
    stack.InsertFront(d);
      break;
  default:
      badInput e;
      throw e;
      break;
  }
  return false;
}

int main() {
  Dlist<double> stack;

  bool done = false;
  while (!done) {
    try {
      done = DoOne(stack);
    } catch (emptyList e) {
      std::cout << "Not enough operands\n";
    } catch (divZero e) {
      std::cout << "Divide by zero\n";
    } catch (badInput e) {
      std::cout << "Bad input\n";
    }
  }
}
