#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MOD (int)(1e9+7)

#define MAX 110000
int A[MAX];

signed main(){
  int N, sum = 0, hoge;
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin>>N;

  hoge = N*(N+1)/2;

  for(int i = 0; i < N; i++){
    cin>>A[i];
    sum += A[i];
  }

  //cout<<hoge<<" "<<sum<<endl;
  if(sum%hoge){
    cout<<"NO"<<endl;
    return 0;
  }
  
  hoge = sum/hoge;

  sum = 0;

  for(int i = 0; i < N; i++){
    int a = A[(i+1)%N]-A[i];
    if(a > hoge || a < hoge*(-(N-1))){
      cout<<"NO"<<endl;
      return 0;
    }
    //cout<<a<<" "<<hoge<<" "<<(a-hoge)<<" "<<(a-hoge)%5<<endl;
    if((a-hoge)%N){
      cout<<"NO"<<endl;
      return 0;
    }
    sum += a;
  }

  if(sum){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
  
  return 0;
}
