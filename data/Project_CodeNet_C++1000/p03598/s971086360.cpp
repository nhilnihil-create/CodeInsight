#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
const double pi = 3.141592653589793;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> x(n);
    rep(i,n)cin>>x[i];
    int ans=0;
    rep(i,n){
        ans += 2*min(x[i],abs(k-x[i]));
    }
    cout<<ans<<endl;
}