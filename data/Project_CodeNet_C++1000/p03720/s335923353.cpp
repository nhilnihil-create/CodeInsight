#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,x;
  cin>>n>>m;
  vector<int> scores(n);
  for(int i=0; i<m*2; i++){
    cin>>x;
    scores.at(x-1)++;
  }
  for(int i=0; i<n; i++){
    cout<<scores.at(i)<<endl;
  }
}