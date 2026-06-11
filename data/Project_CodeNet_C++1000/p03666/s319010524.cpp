#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
long double eps = 1e-9;
long double pi = acos(-1);



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    n--;
    d = d-c;
    for(ll i=0;i<=n;i++){
        ll ret = a + i*c - (n-i)*c;
        // + (0~i)*d - (0 ~ (n-i))*d
        if(b <= ret+i*d && b>= ret-(n-i)*d){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";


}