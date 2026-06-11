#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i = 0;i < int(n);i++)
#define rloop(i,n) for(int i = int(n);i >= 0;i--)
#define range(i,a,b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1,v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define endl '\n'

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;
ll benfit[N];
int add[N];
vi del[N];
ll ans;
int arr[N];
int n , m;

void solve(int st , int ed){
    if(st > ed)ed += m;
    ans += (ed - st);
    if(st+1 == ed)return;
    add[st+2]++;
    del[ed+1].pb(ed+1-(st+2));
}

int main()
{

#ifndef ONLINE_JUDGE
	//freopen("in.in", "r", stdin);
	//freopen("out.in", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    loop(i,n)cin >> arr[i];
    loop(i,n-1)solve(arr[i],arr[i+1]);
    ll cur = 0;
    ll have = 0;
    range(i,1,m+m){
        for(int val : del[i])
            cur -= val , have--;
        have += add[i];
        cur += have;
        benfit[i > m ? i-m : i] += cur;
    }

    ans -= *max_element(benfit,benfit+m+2);
    cout << ans << endl;



    return 0;
}
