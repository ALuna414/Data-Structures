// Run in Repl.it
// clang++-7 -pthread -std=c++17 -o bst_depth bst_depth.cpp; ./bst_depth < bst_depth1.in
//Run in zeus.cs.txstate.edu:
//g++ -pthread -o bst_depth bst_depth.cpp; ./bst_depth < bst_depth1.in

#include <iostream>
#include <sstream>
#include <vector>

/** QUESTION 5: DEPTH AND PATH **/

// EFFECTS: Returns the depth of the target node. Modifies the path vector
//          so that it contains the node values in the path from the root to
//          the target node.
// 
// PSEUDOCODE: GetDepthAndPath
// algorithm
//   Input:
//   Output:
//   Your pseudocode goes here.
// DPHelper ()
//   int declare of depth and count
//   path.pushback()
//   if loop bst[count] not equal target
//     if bst[count] greater than target
//       count equal to right traversal code
//     else if bst[count] less than target
//       count equals to left traversal code
//     depth plus 1
//     DPHelper function call
//   depth plus one
//   return depth
// GetDepthAndPath ()
//   int of depth and count equal to 0
//   return DPHelper function call
//
// COMMENTS:
//   Since using a helper function worked for the previous one, I decided
//   to do it again. Helper would carry the load and since we had to get
//   depth I would take that into account with a count variable to check at
//   each level. Throwing in an if statement with nested if loops as well to
//   check number with target and if it fits then accordingly traverse
//   left side or right side. Call helper function with variables and run
//   recursively. At the end then return the depth of where we made it to
//   and show what the path was taken, Regular function would declare two
//   variables to ease calcualtions needed to pass through with helper.
//
int DPHelper (std::vector<int> &bst, int target, std::vector<int>&path, int depth, int count) {
    path.push_back(bst[count]);
    
    if (bst[count] != target) {
        if (bst[count] > target) {
            count = (count*2)+1;
        }
        else if (bst[count] < target) {
            count = (count*2)+2;
        }
        depth++;
        DPHelper(bst, target, path, depth, count);
    }
    
    depth++;
    return depth;
}

int GetDepthAndPath(std::vector<int> &bst, int target, std::vector<int> &path) {
    int depth = 0, count = 0;
    return DPHelper(bst, target, path, depth, count);
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main() {
  std::vector<int> bst;
  std::string input;
  getline(std::cin, input);
  std::stringstream iss(input);
  int number;
  while (iss >> number) {
    bst.push_back(number);
  }
  int target;
  std::cin >> target;
  
  std::vector<int> path;
  int depth = GetDepthAndPath(bst, target, path);

  std::cout << "depth = " << depth << std::endl;
  std::cout << "path = ";
  for(int i = 0; i < path.size(); i++) {
    std::cout << path[i] ;
    if (i < path.size() - 1) {
      std::cout << " ";
    }
  }
  return 0;
}
