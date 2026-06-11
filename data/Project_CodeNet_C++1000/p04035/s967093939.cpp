#include <iostream>
#include<algorithm>
#include<vector>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int re(int i){return (i/2)*2;}
int solve(int i,int j,int l){
    return re(i)+re(j)+re(l);
}
#define vel vector<long long>
int ret(int i,int j){
    for(int k=i;k<=j;k++){
        cout <<k<<endl;
    }
}
int rev(int i,int j){
    for(int k=j;k>=i;k--){
        cout <<k<<endl;
    }
}
signed main(void){
    int n,l;cin >>n>>l;
    vel a(n);
    rep(i,n){cin >>a[i];}
    for(int i=0;i<n-1;i++){
        if(a[i]+a[i+1]>=l){
            cout << "Possible"<<endl;
            ret(1,i);
            rev(i+2,n-1);
            ret(i+1,i+1);
            return 0;
        }
    }
    cout << "Impossible"<<endl;
}
