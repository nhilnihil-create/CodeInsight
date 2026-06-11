#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
複雑すぎて法則みえないな。必ずNになるとか？

   1
 1 2 3 =2
 
 3
    3
  2 3 4
1 2 3 4 5

    3
  2 4 3
1 5 2 4 3

    2
  2 2 3
5 1 2 3 4

    2
  4 2 2
4 5 1 2 3

    2
  2 2 3
  2 2
  2 2
3 2 1 4
  さえおさえておけばいいのね
*/
int main(){
  ll N,x; cin>>N>>x;
  vector<ll> ans(2*N,0);
  vector<bool> is_use(2*N,false);
  if(x==1 || x==2*N-1){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  if(N==2){
    cout<<1<<endl<<2<<endl<<3<<endl;
    return 0;
  }
  else if(x>=3){
    ans[N-2]=x-1;
    ans[N-1]=x;
    ans[N]=x+1;
    ans[N+1]=x-2;
    for(int i=x-2; i<=x+1; i++)
      is_use[i]=true;
    for(int i=1, j=1; i<=2*N-1; i++){
      if(i==N-2) i+=4;
      if(j==x-2) j+=4;
      ans[i]=j++;
    }
  }
  else if(x==2){
    ans[N-2]=3;
    ans[N-1]=2;
    ans[N]=1;
    ans[N+1]=4;
    for(int i=1; i<=4; i++)
      is_use[i]=true;
    for(int i=1, j=1; i<=2*N-1; i++){
      if(i==N-2) i+=4;
      if(j==1) j+=4;
      ans[i]=j++;
    }
  }
  for(int i=1; i<=2*N-1; i++)
    cout<<ans[i]<<endl;
}