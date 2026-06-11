#include<bits/stdc++.h>
#define mino "frequency"
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define matrix vector<vector<ll>>
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define Down(i,a,b) for(int i=a; i>=b; i--)
#define FOR_(i,a,b) for(int i=a; i<b; i++)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e9

const int N = 1e5 + 5;

using namespace std;

typedef pair<int,int> pii;


int n;
ll kq[N];
struct ii
{
    int val, pos;
};
ii a[N];

bool cmp(ii A, ii B)
{
    return A.val > B.val || (A.val == B.val && A.pos < B.pos);
}

void nhap()
{
    cin >> n;
    FOR(i,1,n)
    {
        cin >> a[i].val;
        a[i].pos = i;
    }
    sort(a+1,a+n+1,cmp);
}

void xuli()
{
    //FOR(i,1,n) cout << a[i].val << ' ' << a[i].pos << endl;
    a[n+1].val = 0;
    int mi = a[1].pos;
    FOR(i,2,n+1)
    {
        kq[mi] += 1ll * (i - 1) * (a[i-1].val - a[i].val);
        mi = min(mi, a[i].pos);
    }
    FOR(i,1,n) cout << kq[i] << endl;
}

int main()
{
    //freopen(mino".inp","r",stdin);
    //freopen(mino".out","w",stdout);
    turbo
    nhap();
    xuli();
}
