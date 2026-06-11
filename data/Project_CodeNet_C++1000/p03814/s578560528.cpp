#include<bits/stdc++.h>
using namespace std;

int main(){
 bool run = 1;
 string s;
 cin >> s;
 int inda = -1,indz = -1;
 for(int i = 0; i < s.length(); i++){
    if(s[i] == 'A' && run == 1){
       inda = i;
      run = 0;
    }
   else if(s[i] == 'Z')
      indz = i; 
 }
 cout << indz - inda + 1;
 return 0;
}