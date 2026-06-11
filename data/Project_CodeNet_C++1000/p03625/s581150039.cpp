#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    set<int> st;
    rep(i, n)
    {
        cin >> a[i];
        mp[a[i]]++;
        st.insert(a[i]);
    }
    ll a1,a2 = 0;
    for(auto e:st){
        if(mp[e]>=2){
            a2 = a1;
            if(mp[e] >= 4)a2 = e;
            a1 = e;
        }
    }
    cout << a1 * a2 << endl;
}