#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MOD 1000000007
#define ll long long int
#define pair <ll, ll> pi
#define vector <ll> vi
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a) * (a)
#define ordered_set tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> //greater_equal<ll> or less<ll>
// find_by_key()   order_of_key()
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/*bool comp(string a, string b) {
if (a.size() != b.size()) return a.size() < b.size();
return a < b;
}*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen('input.txt', 'r', stdin);
    //freopen('output.txt', 'w', stdout);
    ll i, j, k, n, m, b, d, t, ans = 0,a,x,y,w,h;
    cin>>w>>h>>n;
    ll dp[5];
    dp[1]=0;
    dp[2]=w;
    dp[3]=0;
    dp[4]=h;
    while(n--){
        cin>>x>>y>>a;
        if(a==1){
            if(x>dp[1]){
                
                dp[1]=x;
            }
        }
        if(a==2){
            if(x<dp[2]){
              
                dp[2]=x;
            }
        }
        if(a==3){
            if(y>dp[3]){
                
                dp[3]=y;
            }
        }
        if(a==4){
            if(y<dp[4]){
                
                dp[4]=y;
            }
        }
    }
    if(dp[2]-dp[1]>=0&&dp[4]-dp[3]>=0){
        cout<<abs(dp[1]-dp[2])*abs(dp[3]-dp[4])<<endl;
    }
    else{
        cout<<0<<endl;
    }

    return 0;
}