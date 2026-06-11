#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int main(){
  int n,a;cin>>n;
  int sum_odd=0,sum4=0;
  rep(i,n){
    cin>>a;
    if(a%2==1)sum_odd++;
    if(a%4==0)sum4++;    
  }
  if(sum_odd+sum4==n)sum4++;
  cout<<(sum_odd>sum4?"No":"Yes")<<endl;
}