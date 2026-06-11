#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
左からかえていきゃいいんじゃないのか
ああ、aにできない場合は次をかえるのか
あまったら末端をひたすらふやすか
10^5文字
aまでになんて必要か出す。
*/
int main(){
  string s; cin>>s;
  ll sz=s.size(),K; cin>>K;
  vector<ll> A(sz,0);
  for(int i=0; i<sz; i++){
    ll rest=0;
    if(s[i]=='a') continue;
    A[i]='z'-s[i]+1;
  }
  for(int i=0; i<sz; i++){
    if(K-A[i]>=0){
      s[i]='a';
      K-=A[i];
    }
  }
  if(K>0){
    K%=26;
    s[sz-1]+=K;
  }
  cout<<s<<endl;
}