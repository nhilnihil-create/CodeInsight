#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a){
  map<int,int>kazu;
  for(int i=0;i<a.size();i++){
    kazu[a.at(i)]++;
    kazu[a.at(i)-1]++;
    kazu[a.at(i)+1]++;
  }
  int ans=0;
  for(auto i:kazu){
    ans=max(ans,i.second);
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  cout << solve(a) << endl;
  return 0;
}