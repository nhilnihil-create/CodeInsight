#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<pair<int,int>> vec(n);
  int i,sum=0;
  for(i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    vec.at(i)=make_pair(a,b);
    sum+=vec.at(i).second-vec.at(i).first+1;
  }
  cout << sum;
}