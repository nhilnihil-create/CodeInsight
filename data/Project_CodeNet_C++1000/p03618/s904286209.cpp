#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  string s;
  cin >> s;
  ll length=s.size();
  sort(s.begin(),s.end());
  queue<ll>que;
  ll count = 1;
  for(int i=1; i<length; i++){
    if(s[i]!=s[i-1]){
      if(count>1) que.push(count);
      count=1;
    }
    else if(s[i]==s[i-1] && i==length-1){
      count++;
      if(count>1) que.push(count);
    }
    else count++;
  }
  
  ll all = length*(length-1)/2;
  ll fact=0;
  while(que.size()>0){
    ll x = que.front();
    que.pop();
    fact+=x*(x-1)/2;
  }
  cout << all-fact+1 << endl;
}
  
  
  
