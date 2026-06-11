#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl '\n'
int mod=1e9+7;
int mod2=998244353;

signed main(){
  string s;
  cin>>s;
  int c=0;
  vector<int> ch(26,0);
  vector<int> ch2(26,0);
  int cnt;
  int id=0;
  while(true){
    c=0;
    cnt=0;
    for(int i=s.size()-1;i>=id;i--){
      c=(c|(1<<(s[i]-'a')));
      ch[s[i]-'a']++;
      if(c==67108863){
        c=0;
        for(int j=0;j<26;j++){
          if(ch[j]==1){
            break;
          }
        }
        ch=ch2;
        //for(int j=0;j<26;j++)ch[j]=0;
        cnt++;
      }
    }
    char x;
    for(int i=0;i<26;i++){
      if(!(c&(1<<i))){
        x='a'+i;
        cout<<x;
        break;
      }
    }
    for(int i=id;i<s.size();i++){
      if(s[i]==x){
        id=i+1;
        break;
      }
    }
    if(cnt==0){
      cout<<endl;
      return 0;
    }
  }
}
