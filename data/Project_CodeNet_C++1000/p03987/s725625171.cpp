// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long
#define mpr make_pair 
#define pii pair<int,int>
typedef long long ll;
#pragma GCC optimize("Ofast")

const int maxn = 2e5+10;
const int mod = 998244353;
const int inf = 1e9+10;

int n, k;
int a[maxn];
int L[maxn], R[maxn];
vector<int> stk;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    for(int i = 1; i <= n; i++)
    {
        cin>> a[i];
        if(stk.size())
            while(a[i] < a[stk.back()])
            {
                stk.pop_back();
                if(stk.empty()) break;
            }
        if(stk.size()) L[i] = stk.back()+1;
        else L[i] = 1;
        stk.push_back(i);
    }
    stk.clear();
    ll ans = 0;
    for(int i = n; i >= 1; i--)
    {
        if(stk.size())
            while(a[i] < a[stk.back()])
            {
                stk.pop_back();
                if(stk.empty()) break;
            }
        if(stk.size()) R[i] = stk.back()-1;
        else R[i] = n;
        stk.push_back(i);

        ans += a[i] * (R[i]-i+1) * (i-L[i]+1);
    }
    cout<< ans;
}

 


 