#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  string s;
  cin>>N>>s;

  //s->0 w->1
  
  for(int z=0;z<=1;z++){
    for(int o=0;o<=1;o++){
      vector<bool>ans(N,1);
      ans[0]=z;
      ans[1]=o;
      for(int i=0;i<N;i++){
        if(i==0){
          if((s[i]=='o'&&!ans[i])||(s[i]=='x'&&ans[i]))ans[N-1]=ans[i+1];
          else if((s[i]=='x'&&!ans[i])||(s[i]=='o'&&ans[i]))ans[N-1]=!ans[i+1];
        }
        else if(i==N-2){
          if((s[i]=='o'&&!ans[i])||(s[i]=='x'&&ans[i])){
            if(ans[i-1]!=ans[i+1]){
              i=N;
            }
          }
          else if((s[i]=='x'&&!ans[i])||(s[i]=='o'&&ans[i])){
            if(ans[i-1]==ans[i+1]){
              i=N;
            }
          }
        }
        else if(i==N-1){
          if((s[i]=='o'&&!ans[i])||(s[i]=='x'&&ans[i])){
            if(ans[i-1]==ans[0]){
              for(auto it:ans){
                if(it)cout<<'W';
                else cout<<'S';
              }
              return 0;
            }
          }
          else if((s[i]=='x'&&!ans[i])||(s[i]=='o'&&ans[i])){
            if(ans[i-1]!=ans[0]){
              for(auto it:ans){
                if(it)cout<<'W';
                else cout<<'S';
              }
              return 0;
            }
          }
        }
        else{
          if((s[i]=='o'&&!ans[i])||(s[i]=='x'&&ans[i]))ans[i+1]=ans[i-1];
          else if((s[i]=='x'&&!ans[i])||(s[i]=='o'&&ans[i]))ans[i+1]=!ans[i-1];
        }
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}
