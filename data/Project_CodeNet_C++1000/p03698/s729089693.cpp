#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  string s;
  ll cnt[26]={0};
  cin>>s;
  rep(i,s.length()){
    cnt[s[i]-'a']++;
  }

  rep(i,26){
    if(cnt[i]>1){
      cout<<"no"<<endl;
      return 0;
    }
  }

  cout<<"yes"<<endl;
  return 0;
}
