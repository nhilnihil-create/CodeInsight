#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
int main(){
    int n;
    cin>>n;
    vector<int64_t> t(n),a(n);
    rep(i,n){
        cin>>t[i]>>a[i];
    }
    for(int i=1;i<n;i++){
        if(t[i]<t[i-1]||a[i]<a[i-1]){
            int64_t k = max(t[i-1]/t[i]+(t[i-1]%t[i]!=0),a[i-1]/a[i]+(a[i-1]%a[i]!=0));
            t[i] *= k;
            a[i] *= k;
        }
    }
    /*
    rep(i,n){
        cout<<t[i]<<" "<<a[i]<<endl;
    }
    */
    cout<<a[n-1]+t[n-1]<<endl;
}