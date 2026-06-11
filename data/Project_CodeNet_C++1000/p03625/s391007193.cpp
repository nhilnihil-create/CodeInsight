#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int>mp;
    rep(i,n)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(),a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    vector<int> cand;
    for (auto &&i : a)
    {
        if(mp[i]>=2)
        {
            cand.push_back(i);
            if (mp[i] >= 4)cand.push_back(i);
        }
    }
    if(sz(cand) < 2)
    {
        cout << 0 << endl;
        return 0;
    }
    
    sort(cand.begin(),cand.end(),greater<int>());

    cout << (ll)cand[0]*(ll)cand[1] << endl;

}