// Run in Repl.it 
// clang++-7 -pthread -std=c++17 -o bst_validator bst_validator.cpp; ./bst_validator < bst_validator1.in
//Run in zeus.cs.txstate.edu:
//g++ -pthread -o bst_validator bst_validator.cpp; ./bst_validator < bst_validator1.in

#include <iostream>
#include <sstream>
#include <vector>

/** QUESTION 4: BST VALIDATOR **/

// EFFECTS: Returns true if the tree is a valid BST, or false otherwise.
// 
// PSEUDOCODE:
// algorithm FindNode
//   Input:
//   Output:
//   Your pseudocode goes here.
// Helper Function()
//   int called right equal to right traversal access code
//   int called left equal to left traversal access code
//   if left tree greater than index of tree or right tree less than index
//     return false
//   else
//   if left less than size
//     helper function call
//   if right less than size
//     helper function call
//   return true
// IsBST()
//   int of size equal to tree size
//   return helper function call
//
// COMMENTS:
//   I came at this and thought right away I am going to use a helper function.
//   This would ease the load of code and make it easier for me to follow. The
//   helper would do all the work as usual in which I would name two variables
//   of left and right for left traversal and right traversal. With each I would
//   use if loops to return false if condition met criteria in outline of project
//   as wanted by teacher. Use left and right compared to size to determine when
//   to call recursively and see if tree is correct. At the end return true.
//   Then for regular function I would declare size variable equal to binary size
//   to use as variable in helper call. 
//
bool IsBSTHelper (std::vector<int> &binary_tree, int size, int index) {
  int right = (2*index) + 2;
  int left = (2*index) + 1;
      if (binary_tree[left] > binary_tree[index] || binary_tree[right] < binary_tree[index]){
       return false;
      }
      else {
        if(left < size) {
          IsBSTHelper (binary_tree, size, left);
        }
        if(right < size) {
          IsBSTHelper (binary_tree, size, right);
        }

      }
  return true;
}
bool IsBST(std::vector<int> &binary_tree) {
      int size = binary_tree.size();
      return IsBSTHelper(binary_tree, size, 0);
}
    

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main() {
  std::vector<int> binary_tree;
  std::string input;
  getline(std::cin, input);
  std::stringstream iss(input);
  int number;
  while (iss >> number) {
    binary_tree.push_back(number);
  }
  if (IsBST(binary_tree)) {
    std::cout << "True";
  } else {
    std::cout << "False";
  }
  return 0;
}
