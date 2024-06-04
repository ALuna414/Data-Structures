/*
 * autocomplete.cpp
 * 
 * The file where you will implement your autocomplete code for Project 4.
 *
 * INSTRUCTOR NOTE: Do not change any of the existing function signatures in
 * this file, or the testcases will fail. 
 */

#include "autocomplete.h"
#include "tree_node.h"
#include <vector>

/** QUESTION 1: FINDNODE **/

// EFFECTS: Traverses the Tree based on the charactes in the prefix and 
//          returns the TreeNode that we end at. If we cannot find a valid node,
//          we return an empty TreeNode. The index variable keeps track of what 
//          character we're at in prefix.
// 
// PSEUDOCODE:
// algorithm FindNode
//   Input:
//   Output:
//   Your pseudocode goes here.
//   check if not node is empty
//   vector TreeNode char children equals node.GetChildren
//   for loop with children size
//    if children value equal equal prefix of index
//        node equals children at index
//        index plus one
//        return FindNode(node, prefix, index);
//    if index greater than 0
//        return node
//    return TreeNode<char>()
//
// COMMENTS:
//   To come at this one I knew i had to check if empty first. Then I had to
//   create TreeNode vairbale that accesses getchildren from tree_node.h. From
//   there I had to run a loop in that allows the access of node and sets it to
//   an index holder. Then increment so it would move on to the next and then
//   recisively call the function. Somwhere I had to place a staement where if
//   index was nothing then just return node and then keep her return at end.
//
TreeNode<char> FindNode(TreeNode<char> node, std::string prefix, int index) {
    if (!node.IsEmpty()) {
        std::vector<TreeNode<char>> children = node.GetChildren();
        
        for (int i = 0; i < children.size(); i++) {
            if (children[i].GetValue() == prefix[index]){
                node = children[i];
                index++;
                return FindNode(node, prefix, index);
            }
        }
    }
    
    if (index > 0) {
        return node;
    }
  
  return TreeNode<char>();
}
/** QUESTION 2: COLLECTWORDS **/

// EFFECTS: Collects all the words starting from a given TreeNode. For each word, 
//          prepends the word with the prefix and adds it to the results vector.
// 
// PSEUDOCODE:
// algorithm CollectWords
//   Input:
//   Output:
//   Your pseudocode goes here.
//   vector TreeNode named children equals node.GetChildren
//   string name equal to prefix
//   for loop up until children size
//   if chidlren.GetValue equal equal $
//     resuts.pushback(name)
//   else prefix.pushback(children.GetValue
//     CollectWords Call
//   prefix equals name
//
// COMMENTS:
//   This one was going to use the previous function since all three questions
//   int this section were used together. I had to create a variable at start
//   ;ike the last to access nodes of children. Would create a string to store
//   and then use loops to travese and access. The use of pushback calls would
//   be helpful and also recursion. What goes inside the loop was just
//   traversing everything throubh needed and into the string to output.
//
void CollectWords(TreeNode<char> node, std::string prefix, std::vector<std::string> &results) {
    std::vector<TreeNode<char>> children = node.GetChildren();
    std::string name = prefix;

    for (int i=0; i < children.size(); i++) {
        if (children[i].GetValue() == '$'){
            results.push_back(name);
        }
        else {
            prefix.push_back(children[i].GetValue());
            CollectWords(children[i], prefix, results);
        }
        
        prefix = name;
    }
}

/** QUESTION 3: GETCANDIDATES **/

// EFFECTS: Returns the list of all possible words that can be made starting with
//          the letters in prefix, based on traversing the tree with the given root.
// 
// PSEUDOCODE:
// algorithm GetCandidates
//   Input:
//   Output:
//   Your pseudocode goes here.
//   vector string named words
//   if prefix equal equal quotations
//     vector TreeNode named children equal root.GetChildren
//     for loop with auto child of children reference
//     prefix equal child.GetValue
//     CollectWords function call
//   else root equal FindNode call
//     if loop with root.GetValue not equal prefix[]
//        return words
//     CollectWords call
//   return words
//
// COMMENTS:
//   Use of second previous function I had to implement. Check right away for prerix
//   being empty and just output quotations. Use veector for auto loop as in slides
//   from previous clasees. This took a while since I had to see how to use it. More
//   loop statment to check what is traversing through and make sure to output in
//   correct search order of words. Recursice calls and in the end return words
//   stored in a new vector string type.
//
std::vector<std::string> GetCandidates(TreeNode<char> root, std::string prefix) {
    std::vector<std::string> words;
    
    if (prefix == "") {
        std::vector<TreeNode<char> > children = root.GetChildren();

        for (auto child : children) {
         prefix = child.GetValue();
         CollectWords(child, prefix, words);
        }
    }
    else {
        root = FindNode(root, prefix, 0);
        
        if (root.GetValue() != prefix[prefix.length()-1]){
            return words;
        }
        
        CollectWords(root, prefix, words);
    }
    return words;
}
