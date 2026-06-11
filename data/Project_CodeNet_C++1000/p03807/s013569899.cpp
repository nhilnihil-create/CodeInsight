#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  int N;
  cin>>N;
  int odd_count=0;
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    odd_count+=A%2;
  }
  if(odd_count%2==0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
