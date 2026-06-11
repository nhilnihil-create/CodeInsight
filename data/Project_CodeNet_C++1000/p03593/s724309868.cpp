#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> a(h);
  rep(i,h) cin>>a[i];
  vector<int> d(26);
  rep(i,h)rep(j,w){
    d[a[i][j]-'a']++;
  }
  vector<int> res(3);
  rep(i,26){
    if(d[i]%4==1) res[0]++;
    else if(d[i]%4==2) res[1]++;
    else if(d[i]%4==3) res[2]++;
  }
  if(h%2!=0&&w%2!=0){
    if(res[0]+res[2]!=1||res[1]+res[2]>h/2+w/2){
      cout<<"No"<<endl;
      return 0;
    }
  }else if(w%2!=0){
    if(res[0]+res[2]!=0||res[1]>h/2){
      cout<<"No"<<endl;
      return 0;
    }
  }else if(h%2!=0){
    if(res[0]+res[2]!=0||res[1]>w/2){
      cout<<"No"<<endl;
      return 0;
    }
  }else{
    if(res[0]!=0||res[1]!=0||res[2]!=0){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}
