#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string a,b;
  cin>>a>>b;
  int s=a.size();
  int t=b.size();
  if(s>t) cout<<"GREATER"<<endl;
  else if(s<t) cout<<"LESS"<<endl;
  else{
    string u="EQUAL";
    rep(i,0,s){
      if(a[i]>b[i]){
        u="GREATER";
        break;
      }
      else if(a[i]<b[i]){
        u="LESS";
        break;
      }
    }
    cout<<u<<endl;
  }
}