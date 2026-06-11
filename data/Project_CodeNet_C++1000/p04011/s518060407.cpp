#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, k, x, y;
  cin>>n>>k>>x>>y;
  int answer;

  if(n<=k){
    answer = n*x;   
  }
  else if(n>k){
    answer = k*x + (n-k)*y;
  }

  cout<<answer<<endl;

}
