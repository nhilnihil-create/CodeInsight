#include <iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int re(int i){return (i/2)*2;}
int solve(int i,int j,int l){
    return re(i)+re(j)+re(l);
}
#define vel vector<long long>
#define rep(i,n) for(int i=0;i<n;i++)
signed main(void){
    int n;cin >>n;
    vel a(n);
    rep(i,n){cin >>a[i];}
    vel s=a;sort(s.begin(),s.end());
    int ans=0;
    for(int i=0;i<n;i+=2){
        int x=lower_bound(s.begin(),s.end(),a[i])-s.begin();
        ans+=(x%2);
    }
    cout <<ans<<endl;
}
