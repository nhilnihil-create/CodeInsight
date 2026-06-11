#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 5000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(){
    int n; cin>>n;
    vector<P> x(n);
    vector<int> ans(n*n,0);
    rep(i,n){
        cin>>x.at(i).F;
        x.at(i).S=i+1;
        ans.at(x.at(i).F-1)=x.at(i).S;
    }
    sort(all(x));
    int cnt1=0,cnt2=0;
    rep(i,n){
        cnt1+=x.at(i).S;
        if(cnt1>x.at(i).F){
            cout<<"No"<<endl;
            return 0;
        }
    }
    reverse(all(x));
    rep(i,n){
        cnt2+=n-x.at(i).S+1;
        if(cnt2>n*n-x.at(i).F+1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    reverse(all(x));
    int at=0;
    rep(i,n){
        rep(j,x.at(i).S-1){
            while(ans.at(at)!=0){
                at++;
            }
            ans.at(at)=x.at(i).S;
        }
    }
    reverse(all(x));
    at=n*n-1;
    rep(i,n){
        rep(j,n-x.at(i).S){
            while(ans.at(at)!=0){
                at--;
            }
            ans.at(at)=x.at(i).S;
        }
    }
    cout<<"Yes"<<endl;
    rep(i,n*n-1)cout<<ans.at(i)<<' ';
    cout<<ans.back()<<endl;
}