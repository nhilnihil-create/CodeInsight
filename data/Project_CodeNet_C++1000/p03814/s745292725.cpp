#include <bits/stdc++.h>
using namespace std;


int main() {
   string s;
   cin >> s;
   int aIndex, zIndex;
   for (int i=0; i<s.size(); i++) {
       if (s.at(i) == 'A') {
           aIndex = i;
           break;
       }
   }
   for (int i=s.size()-1; i>=0; i--) {
       if (s.at(i) == 'Z') {
           zIndex = i;
           break;
       }
   }
   
   cout << zIndex - aIndex + 1 << endl;
}
