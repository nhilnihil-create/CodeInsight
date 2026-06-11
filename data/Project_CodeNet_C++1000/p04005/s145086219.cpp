//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    VL a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(ALL(a));
    if(a[0]%2==0||a[1]%2==0||a[2]%2==0)cout<<0<<endl;
    else if(a[0]%2!=0||a[1]%2!=0||a[2]%2!=0){
        cout<<a[0]*a[1]<<endl;
    }
    return 0;
}