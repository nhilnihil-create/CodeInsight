#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  long long num=1;
  cin>>n;
  for(int i=1;i<=n;i++){
    num=num*i%1000000007;
  }
  cout<<num<<endl;
}
