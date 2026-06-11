#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
//#define int long long
using namespace std;
const int MOD=1000000007;
const int INF=1000000009;



int main(){
  int h,w;
  cin>>h>>w;
  int y,x;
  string s;
  rep(i,h)rep(j,w){
    cin>>s;
    if(s=="snuke"){
      y=i+1;
      x=j;
    }
  }
  cout<<(char)(x+'A')<<y<<endl;
  return 0;
}
