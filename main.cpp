#include "Autocompleter.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  Autocompleter ac;
   // Insert some words into the Autocompleter
  vector<string> words = {"aardvark", "albatross", "alpaca",    "armadillo",
                          "cat",      "camel",     "crocodile", "crow",
                          "giraffe",  "goat",      "goose",     "goatfish",
                          "gorilla"};
  for (const string &word : words) {  // Insert each word into the Autocompleter
    ac.insert(word);
  }
  cout << "Tree size: " << ac.size() << endl; 
  cout << "Tree height: " << ac.height() << endl; 

  cout << "Completions for prefix 'a':" << endl;  
  ac.completions("a"); // Output: aardvark alpaca armadillo

  string userPrefix;
  while (true) {
    cout << "Enter a prefix to search for: (use 'exit' to stop) " << endl; 
    getline(cin, userPrefix);
    if (userPrefix == "exit") {
      break;
    }

    cout << "Completions for prefix '" << userPrefix << "':" << endl; // Output:
    ac.completions(userPrefix); 
  }
  return 0;
}
