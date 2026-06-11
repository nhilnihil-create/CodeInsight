#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main() {
  
  int H,W,N;
  cin>>H>>W>>N;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  queue<int>q;
  rep(i,N){
    int p=a.at(i);
    while(p--){
      q.push(i+1);
    }
  }
  rep(i,H){
    vector<int>ans(W);
    int w=W;
    while(w--){
      ans.at(W-1-w)=q.front();
      q.pop();
    }
    if(i%2==0){
      rep(i,W){
        cout<<ans.at(i)<<" ";
      }
    }
    else{
      rep(i,W){
        cout<<ans.at(W-1-i)<<" ";
      }
    }
    cout<<endl;
  }
}