#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    vector<int> c(3);
    rep(i,3) cin>>c[i];
    sort(etob(c));
    int ans=c[1]+c[2];
    cout<<ans<<endl;
    return 0;
}