#include <bits/stdc++.h>
using namespace std;
int main(){
   string s;
   cin >> s;
   for(int i=0;i<12;i++){
       if(i==4) cout << ' ';
       cout << s[i];
   }
   cout << endl;
}