#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLMAX (1ll << 60) - 1
#define INTMAX (1 << 30) - 1
#define MOD 1000000007 
#define NMAX 1000*100+1

#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define isOn(S, j) (S & (1 << j))
#define endl '\n'
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;
#define printii(x)  for(auto it:x) cout<<it.F<<' '<<it.S<<'\t';  cout<<endl;
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define vvii vector<vii>
#define viii vector<pair<ii,ll>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mc(a,b,c) mp(mp(a,b),c)

vvi a,b;
viii edj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,t,m,y,z;
    cin>>n;
    a.assign(n,vi(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(j>i)edj.pb(mc(a[i][j],i,j));
        }
    }
    b = a;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]); 
            }
        }
    }
    if(a!=b){
        cout<<-1;
        return 0;
    }

    ll d = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            bool ok = true;
            for(int k=0;k<n;k++){
                if((a[i][j]==(a[i][k]+a[j][k]))&&(k!=i)&&(k!=j)){
                    ok = false;
                }
            }
            if(ok)
            d+=a[i][j];
        }
    }
    cout<<d;
    
    

    



    return 0;
}