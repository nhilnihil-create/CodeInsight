#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
 #define rep(i, n) for (int i = 0; i < (int)(n); i++)
 #define big 1000000007
 #define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
int main(){
    int k,t;
    cin>>k>>t;
    vector<int> a(t);
    rep(i,t){
        cin>>a[i];
    }
    all(a);
    Re(a);
    int ans = a[0]-1;
    for(int i=1;i<t;i++){
        ans -= a[i];
    }
    cout<<max(0,ans)<<endl;
}