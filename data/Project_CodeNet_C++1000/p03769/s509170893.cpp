//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (99991LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> i4;



vector<int> calc(int n, ll rem){
    if(rem == 1)  return vector<int> (0);
    if(rem % 2 == 0){
        vector<int> ans = calc(n-1, rem/2);
        ans.pb(n);
        return ans;
    }
    vector<int> ans = calc(n-1, rem-1);
    ans.insert(ans.begin(), n);
    return ans;
}
 
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll rem;
    cin>>rem;

    vector<int> ans = calc(100, rem+1);
    int lo = 100 - (int)ans.size() + 1;

    cout<<2*(int)ans.size()<<endl;
    for(auto it : ans)
        cout<<it<<" ";
    for(int i=lo;i<=100;i++)
        cout<<i<<" ";
     
    return 0;
}
 







