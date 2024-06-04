// Run in Repl.it
// clang++-7 -pthread -std=c++17 -o bst_lca bst_lca.cpp; ./bst_lca < bst_lca1.in
//Run in zeus.cs.txstate.edu:
//g++ -pthread -o bst_lca bst_lca.cpp; ./bst_lca < bst_lca1.in
#include <iostream>
#include <sstream>
#include <vector>

/** QUESTION 6: LOWEST COMMON ANCESTOR **/

// EFFECTS: Returns the value of the lowest common ancestor of nodes l and m.
// 
// PSEUDOCODE:
// algorithm GetLCA
//   Input:
//   Output:
//   Your pseudocode goes here.
//   int of parent equal to array index 0
//   int of parentcount equal to 0, parentcount equal 0
//   for loop until bst size
//     if bst[index] equal equal l
//       parentcount equal to i
//       parentcount minues equal to 1
//       parentcount equal to parentcount divided by 2
//       parentcount equal to bst[ParentLCount]
//     if bst[index] equal equal m
//       parentcount equal to i
//       parentcount minues equal to 1
//       parentcount equal to parentcount divided by 2
//       parentcount equal to bst[ParentLCount]
//     if parent equal to other parent and parent greater than 0
//       return parent
//   int test equal parentcount
//   int test equal parentcount
//   while test greater than 0 and other test greater than 0
//    test minus equal 1
//    test divided equal 2
//    test2 minus equal 1
//    test2 divided equal 2
//    if test equals other test
//      return bst[test]
//    else if test2 compares to parentcount
//        return parentL
//    else if test compares to parentcount
//        return parentM
//   return bst[0]
//
// COMMENTS:
//   This one was easy to picture but hard for me to get on and write code for. I knew
//   the mission and understood but didn't really know a straight path to get there.
//   I would declare variables of counts and parent variables of both l and m. From there
//   use a for loop to traverse through numbers and with if statements decide to see
//   where numbers where in common and output parent of both whether that was two
//   generations behind or one. Would do this for both l and m and then more comparision
//   loops to decide which parent to output. Add in some test variables for the parents
//   in case numbers where from different siblings. 
//
int GetLCA(std::vector<int> &bst, int l, int m) {
    int ParentL = bst[0], ParentM = bst[0];
    int ParentLCount = 0, ParentMCount = 0;
    
    for(int i=0; i < bst.size(); i++) {
        if (bst[i] == l) {
            ParentLCount = i;
            ParentLCount -= 1;
            ParentLCount = ParentLCount/2;
            ParentLCount = bst[ParentLCount];
        }
        if (bst[i] == m) {
            ParentMCount = i;
            ParentMCount -= 1;
            ParentMCount = ParentMCount/2;
            ParentMCount = bst[ParentMCount];
        }
        if (ParentL == ParentM && ParentMCount > 0) {
            return ParentL;
        }
    }
    
    int test = ParentLCount, test2 = ParentMCount;
    
    while (test > 0 && test2 > 0) {
        test -= 1;
        test /= 2;
        test2 -= 1;
        test2 /= 2;
        
        if (test == test2) {
            return bst[test];
        }
        else if (test2 == ParentLCount) {
            return ParentL;
        }
        else if (test == ParentMCount) {
            return ParentM;
        }
    }
  return bst[0];
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
  int l, m;
  std::cin >> l;
  std::cin >> m;
  
  std::vector<int> path;
  int lca = GetLCA(bst, l, m);

  std::cout << "lca = " << lca;
  return 0;
}
