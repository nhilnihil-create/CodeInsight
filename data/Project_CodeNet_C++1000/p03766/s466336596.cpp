#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
typedef long long LL;
typedef pair<int,double> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

static const int MAX_SIZE = 1 << 22; 

LL segMax[2 * MAX_SIZE - 1], segAdd[2 * MAX_SIZE - 1];

void add(int a, int b, LL x, int k = 0, int l = 0, int r = MAX_SIZE)
{
    if (r <= a || b <= l) return;

    if (a <= l && r <= b){
        segAdd[k] = (segAdd[k] + x)%mod;
        return;
    }

    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    add(a, b, x, k * 2 + 2, (l + r) / 2, r);

    segMax[k] = max(segMax[k * 2 + 1] + segAdd[k * 2 + 1], segMax[k * 2 + 2] + segAdd[k * 2 + 2])%mod;
}

LL getMax(int a, int b, int k = 0, int l = 0, int r = MAX_SIZE)
{
    if (r <= a || b <= l) return 0;

    if (a <= l && r <= b) return (segMax[k] + segAdd[k])%mod;

    LL left = getMax(a, b, k * 2 + 1, l, (l + r) / 2);
    LL right = getMax(a, b, k * 2 + 2, (l + r) / 2, r);

    return (max(left, right) + segAdd[k])%mod;
}

int main(){
    LL n;cin >> n;
    LL ans = 0;
    add(0, 1, 1);
    for (int i = 0; i < n; i++) {
        LL d = getMax(i, i + 1);
        if(i == n - 1){
            ans = (ans + d * n) %mod;
        }
        else{
            add(i + 1, i + 2, d);
            add(i + 3, i + 2 + n, d);
            ans = (ans + d * (n - 1) %mod * (n - 1)) %mod;
        }
    }
    for (int i = n; i <= 2 * n; i++) {
        ans = (ans + getMax(i,i+1))%mod;
    }
    cout << ans << endl;
    return 0;
}
