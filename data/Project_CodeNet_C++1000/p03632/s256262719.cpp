#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int a,b,c,d,ans;
    cin >> a>>b>>c>>d;
    int start,end;
    start = ::max(a,c);
    end = ::min(b,d);
    if(end-start < 0){
        ans = 0;
    }else{
        ans = end-start;
    }
    cout<<ans<<endl;
}