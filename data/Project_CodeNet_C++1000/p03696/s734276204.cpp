#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  string S;
  cin>>N>>S;
  int cnt1=0,cnt2=0;
  for(int i=0;i<N;i++){
    if(S[i]==')'){
      if(cnt1==0)
        cnt2++;
      else
        cnt1--;
    }else
      cnt1++;
  }
  for(int i=0;i<cnt2;i++)
    cout<<'(';
  cout<<S;
  for(int i=0;i<cnt1;i++)
    cout<<')';
  cout<<endl;
}