#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    // 54
    int N;
    cin >> N;
    int l,r,ans=0;
    rep(i,N){
        cin>>l>>r;
        ans += (r-l)+1;
    }
    cout<<ans<<endl;
}