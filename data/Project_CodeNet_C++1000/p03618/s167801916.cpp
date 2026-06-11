#include <bits/stdc++.h>

using namespace std;

int main(){
  long long R[400009];
  string s;
  cin >> s;
  long long n = s.length();
  map<char, int> mp;
  for(int i=0;i<n;i++)mp[s[i]]++;
  long long ans=n*(n-1)/2;
  for(auto& p: mp){
    long long value=p.second;
    ans -= value*(value-1)/2;
  }
  cout << ans+1 << endl;
}

