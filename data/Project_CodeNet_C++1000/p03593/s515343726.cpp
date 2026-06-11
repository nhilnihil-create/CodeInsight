#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int H,W;
  cin>>H>>W;
  vector<int> A(26);
  for(int i=0;i<H*W;i++){
    char c;
    cin>>c;
    A[c-'a']++;
  }
  int cnt1=0,cnt2=0;
  for(int i:A){
    if(i%2==1)
      cnt1++;
    if(i%4==2)
      cnt2++;
  }
  if(cnt1>H*W%2 || cnt2>H/2*(W%2)+W/2*(H%2))
    puts("No");
  else
    puts("Yes");
}