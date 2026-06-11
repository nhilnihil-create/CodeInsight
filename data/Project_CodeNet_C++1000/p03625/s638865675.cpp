/**
 * @author: Mackenzie
**/
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin>>n;
    map<int,int> mp;
    set<int> st;
    forn(i,n){
        int x;
        cin>>x;
        st.insert(x);
        mp[x]++;
    }
    ll a=0,b=0;
    for(auto it=st.rbegin();it!=st.rend();it++){
        if(mp[*it]>=4&&a==0){
            a=*it;
            b=*it;
            break;
        }else if(mp[*it]>=2){
            if(a==0)a=*it;
            else{
                b=*it;
                break;
            }
        }
    }
    cout<<a*b<<endl;
    return 0;
}
