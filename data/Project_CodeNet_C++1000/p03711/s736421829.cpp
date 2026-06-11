#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int group(int n){
    if(n==2)return 2;
    else if (n==4 || n==6|| n==9 || n==11) return 1;
    else return 3;
}
int main(){
    int x,y;cin>>x>>y;
    int X=group(x);
    int Y=group(y);
    if(X==Y)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;    
}
