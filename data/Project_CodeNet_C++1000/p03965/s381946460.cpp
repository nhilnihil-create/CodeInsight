#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define Rep(i, r, n) for (ll i = r; i < n; i++)
#define debug(x) cout << #x << " = " << (x) << endl;
#define pb push_back
#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000000000
#define EPS 0.00000000001
typedef long long ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    //---------------------------------------------
    
    string s;
    cin>>s;
    int n=s.size();
    int count=0;
    int ans=0;
    int gc=0;
    rep(i,n){
        if(gc==0){
            if(s[i]=='g'){
                //g vs g
                gc++;
            }
            else{
                ans--;
                gc++;
            }
        }
        else{
            if(s[i]=='g'){
                gc--;
                ans++;
            }
            else{          
                gc--;
            }
        }
    }
    cout<<ans<<endl;

}
