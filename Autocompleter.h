#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Autocompleter  
{
   private:
      struct TreeNode  //TreeNode struct
{
   string word;
  TreeNode* left; //left subtree
  TreeNode* right;  //right subtree
  TreeNode(string w) : word(w), left(nullptr), right(nullptr) {} //constructor
};
  TreeNode* root; 

TreeNode* insert(TreeNode* node, const string& word) //insert function
{
  if (!node)  
    return new TreeNode(word);  // Base case
  if (word < node->word)
    node->left = insert(node->left, word);  //left subtree
  else if (word > node->word) node->right = insert(node->right, word); //right subtree
  return node; 
}

int size(TreeNode* node) const //size function
{
  if (!node) return 0;
  return 1 + size(node->left) + size(node->right);  //size of left and right subtree
}
  int height(TreeNode* node) const //height function
{
  if (!node) return -1;
  return 1 + max(height(node->left), height(node->right)); //max height of left and right subtree
}
  void completions(TreeNode* node, const string& prefix, vector<string>& results) const //completions function
{
  if (!node) return; //base case
    completions(node->left, prefix,results); //left subtree

  if (node->word.find(prefix) == 0) //left subtree
  {
    results.push_back(node->word); //adds prefix to results
  }
  completions(node->right, prefix, results); //right subtree
}

public: 
Autocompleter() : root(nullptr) {} //constructor
  void insert(const string& word) //insert function
{
  root = insert(root, word); 
}
  int size() const  //size function
{
  return size(root); //size of tree
}
int height() const  //height function
{
  return height(root); //height of tree
}
void completions(const string& prefix) const  //completions function
{
  vector<string> results; 
  completions(root, prefix, results); //completions of prefix
  for (const string& word : results)  //for loop to print results
    {
      cout << word << endl;
    }
  }
};