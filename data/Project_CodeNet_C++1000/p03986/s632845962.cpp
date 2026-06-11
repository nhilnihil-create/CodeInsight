#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;int S = 0,c = 0,i;cin >> s;
  for(i=0;i<s.size();i++){
    if(s[i]=='S') S++;
    else if(s[i]=='T' && S>0){
      c++;S--;
    }
  }
  cout << s.size()-c*2 << "\n";
}