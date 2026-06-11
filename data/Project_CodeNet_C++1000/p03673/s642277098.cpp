#include <bits/stdc++.h>
#define rep(i,n) for (int64_t i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n; cin>>n;
    vector<int> p(n),q(n);
    rep(i,n) cin>>p[i];
    int s=n/2;
    if(n%2==0){
        rep(i,n){
            q[s]=p[i];
            if(i%2==0){
                s-=(i+1);
            }
            else s+=(i+1);
        }
    }
    else{
        rep(i,n){
            q[s]=p[i];
            if(i%2==0) s+=(i+1);
            else s-=(i+1);
        }
    }
    rep(i,n){
        cout<<q[i]<<" ";
    }
    cout<<endl;
    return 0;
}