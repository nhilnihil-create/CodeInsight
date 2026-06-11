#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  string w;
  cin>>w;
  int cnt[26]={0};
  rep(i,w.length()){
    cnt['z'-w[i]]++;
  }
  rep(i,26){
    // cout<<cnt[i]<<endl;
    if(cnt[i]%2!=0){
      cout<<"No"<<endl;
      return 0;
    }
  }


  cout<<"Yes"<<endl;
  return 0;
}
