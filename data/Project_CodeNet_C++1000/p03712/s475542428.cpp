#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int ATUI, SAMUI;
  string YUNI, KUROE = "#";
  vector<string> OOT(200);
  
  cin >> ATUI >> SAMUI;
  
  for(int JNY =0; JNY < ATUI; JNY++){
    cin >> OOT.at(JNY);
  }
  
  for(int JNY =0; JNY < SAMUI + 2; JNY++){
    YUNI += '#';
  }
  
  cout << YUNI << endl;
  for(int JNY =0; JNY < ATUI; JNY++){
    cout << KUROE + OOT.at(JNY) + KUROE << endl;
  }
  cout << YUNI << endl;
}