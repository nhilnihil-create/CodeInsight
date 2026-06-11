#include <bits/stdc++.h>

using namespace std;
int main(){
 string s, ans;
 cin >> s;
 int cnt=0;

 for(int i = 0 ; i < s.length() ; i++){
   if(s[i] == '0'){
    ans[cnt] = '0';
    cnt++;
  }else if(s[i] == '1'){
   ans[cnt] = '1';
    cnt++;
  }else if(cnt !=0){
    cnt--;
    ans[i] = ' ';
    }
  }

  for(int i = 0 ; i < cnt ; i++){
    cout << ans[i] ;
  }
  cout << endl;
}
