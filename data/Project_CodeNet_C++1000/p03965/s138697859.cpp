
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1001001001;


int main(){
  string s;
  cin>>s;
  int n,cnt,sc;
  n=s.size();
  cnt=0;sc=0;
  rep(i,n){
    if (cnt>0){
      if (s[i]=='g')sc++;
      cnt--;
    }
    else{
      if (s[i]=='p')sc--;
      cnt++;
    }
    //cout<<sc<<endl;
  }
cout<<sc;
}
