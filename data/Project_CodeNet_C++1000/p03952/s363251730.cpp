#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#include <cctype>
#include <locale>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<long long,long long> Pll;
#define fout(num) cout << fixed << setprecision(20) << (num) << endl
//s[i]=tolower(s[i]); islower(s[i]); cout << tolower(s[i])はバグ
//vector<vector<ll>> dp(n,vector<ll>(n))
//exist x map o setconst ll MOD = 1e9+7;return fac[n]*(finv[k]*finv[n-k] % MOD) % MOD;
//2-dim:vector<vector<Type>> vv(n, vector<Type>(m, d));
//3-dim:vector<vector<vector<Type>>> vvv(n, vector<vector<Type>>(m, vector<Type>(l, d)));


signed main(){
    int n; cin >> n;
    int x; cin >> x;
    n=2*n-1;
    if(n==3){
        if(x==2){
            cout << "Yes" << endl;
            cout << 1 << endl;
            cout << 2 << endl;
            cout << 3 << endl;
        }
        else cout << "No" << endl;
    }
    else if(x==1||x==n){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        vector<int> v(n,-1);
        vector<bool> ok(n,1);
        int mid=n/2;
        v[mid-1]=x-1; ok[x-2]=0;
        v[mid]=x; ok[x-1]=0;
        v[mid+1]=x+1; ok[x]=0;
        if(x-2>0){ v[mid+2]=x-2; ok[x-3]=0; }
        else{ v[mid-2]=x+2; ok[x+1]=0; }
        int j=0;
        rep(i,n){
            if(v[i]==-1){
                while(j<n&&!ok[j]) j++;
                v[i]=j+1; ok[j]=0;
            }
        }
        rep(i,n) cout << v[i] << endl;
    }
}


