#include <bits/stdc++.h>
using namespace std;

int main(){
   string s; cin >> s;
   int bucket[26] = {0};

   for(int i=0; i<s.size(); i++) {
      int tmp = s[i] - 'a';
      bucket[tmp] = 1;
   }

   for(int i =0; i < 26; i++) {
      if (bucket[i] != 1) {
         printf("%c\n", i + 97);
         return 0;
      }
   }
   cout << "None" << endl;
   return 0;
}
