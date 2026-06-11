#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    
    if(a[n-1]-a[0]>=2){
        cout<<"No"<<endl;
        return 0;
    }
    
    if(a[0]==a[n-1]){
        int x=a[0];
        if(n==x+1 || n>=x*2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else{
        int x=a[0];
        int now=0;
        while(a[now]==x) now++;
        
        if(now<x && n-now>=(x-now+1)*2) cout<<"Yes"<<endl;
        else if(now==x && n-now>=2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
