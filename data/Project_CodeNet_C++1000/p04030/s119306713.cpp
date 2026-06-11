#include <bits/stdc++.h>
using namespace std;

int main(void){
   
 string s;
 vector<char>ans;
 
 cin >> s;
 int len = s.size();
 
 for(int i=0;i<len;i++){
     if(s[i] == '0'){
         ans.push_back('0');
     }
     else if(s[i] == '1'){
         ans.push_back('1');
     }
     else{
         if(ans.size() > 0) ans.pop_back();
     }
 }
 int ans_size = ans.size();
 for(int i=0;i<ans_size;i++) cout << ans[i];
 cout << endl;
}