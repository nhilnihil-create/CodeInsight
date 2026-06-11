#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin>>n;
  int sum = 0;
  vector<int> l(n),r(n);
 
  rep(i,n){
    cin>>l.at(i)>>r.at(i);
    sum += r.at(i)-l.at(i)+1;
  }
  cout<<sum<<endl;
}