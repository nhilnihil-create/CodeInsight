#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t,u;
  cin >> s >> t >> u;
  if(s.at(s.size()-1)==t.at(0) && t.at(t.size()-1)==u.at(0)){
    cout << "YES";
  }else{
     cout << "NO";
  }
}