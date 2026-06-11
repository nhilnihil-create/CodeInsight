#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define uid uniform_int_distribution
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define bpop(x) __builtin_popcountll((ulli)x)
#define blead(x) __builtin_clzll((ulli)x)
#define btrail(x) __builtin_ctzll((ulli)x)
const double PI = acos(-1);
template<class my>
using ind_set = tree<my,null_type,less<my>,rb_tree_tag,tree_order_statistics_node_update>;

// primes - 31 53 (1-3)67 1(0-1)87 125(6-8)87 3256(0-9)7
// primes - 569(6-8)09 1299709 2750159 154858(57-63-67) 998244353

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ppb pop_back()
#define ppf pop_front()
#define all(vec) vec.begin(), vec.end()
#define fol(i,a,b) for(int i=a;i<b;i++)
#define loop(i,a,b) for(int i=a;i>=b;i--)
#define forr(x,arr) for(auto& x:arr)
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-7
#define sz(x) ((lli)(x).size())

using   lli     =   long long;
using   lld     =   long double;
using   ulli    =   unsigned long long int;
using   pll     =   pair<lli, lli>;
using   ttt     =   pair<lli, pll>;
using   vttt    =   vector<ttt>;
using   vll     =   vector<pll>;
using   vl      =   vector<lli>;
using   vi      =   vector<int>;
using   vvi     =   vector<vector<int>>;
using   cd      =   complex<lld>;

#ifdef tejasp
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.ff); __p(a.ss); cout << "} "; }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";__p(arg1); cout<<endl;
}
template<typename Arg1>
void __t(const char *name, Arg1 &&arg1)
{ cout<<name<<" : { "; for (auto p : arg1) __p(p); cout<<"}"<<endl; }
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(; ;i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    cout.write(names,i)<<" : ";
    __p(arg1);  cout<<"| ";
    __f(names+i+1,args...);
}
template<typename Arg1, typename Arg2>
void __f(const char *names, Arg1 arg1[], Arg2 &&arg2){
    int i=0;
    for(; ;i++) if(names[i]==',') break;
    cout.write(names,i)<<" : { ";
    fol(i,0,arg2) __p(arg1[i]);
    cout << "} "<<endl;
}
#define trace(...) { cout<<"Line:"<<__LINE__<<" | "; __f(#__VA_ARGS__, __VA_ARGS__); }
#define cotra(...) { cout<<"Line:"<<__LINE__<<" | "; __t(#__VA_ARGS__, __VA_ARGS__); }
#define localsys 1
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define trace(...) {}
#define cotra(...) {}
#define end_routine() {}
#define localsys 0
#define endl '\n'
#endif

int sparse[19][100010], rsparse[19][100010];
int lim=19;

int tejas_919(int kkkk)
{
    lli n, m, k, q, u, v, temp=0, ans=0;
    cin>>n;
    int arr[n+5]={};
    fol(i,0,n) cin>>arr[i];
    cin>>m;
    {
        k=0;
        fol(i,0,n)
        {
            while ( k<n && (arr[k]-arr[i]) <=m ) k++;
            k--;
            sparse[0][i]=k;
        }
        fol(i,1,lim) fol(j,0,n) sparse[i][j]=sparse[i-1][sparse[i-1][j]];
    }
    {
        k=n-1;
        loop(i,n-1,0)
        {
            while ( k>=0 && (arr[i]-arr[k]) <=m ) k--;
            k++;
            rsparse[0][i]=k;
        }
        fol(i,1,lim) fol(j,0,n) rsparse[i][j]=rsparse[i-1][rsparse[i-1][j]];
    }
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        u--; v--;
        ans=0;
        if(u<v)
        {
            loop(j,lim-1,0)
            {
                if(sparse[j][u]<v)
                {
                    ans+=(1LL<<j);
                    u=sparse[j][u];
                }
            }
            ans++;
        }
        else if (u>v)
        {
            loop(j,lim-1,0)
            {
                if(rsparse[j][u]>v)
                {
                    ans+=(1LL<<j);
                    u=rsparse[j][u];
                }
            }
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

signed main()
{
    #ifdef tejasp
            freopen("input.txt", "rt", stdin);
            freopen("output.txt", "wt", stdout);
    #endif
    if(!localsys) { ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); }
    cout << fixed << setprecision(10);
    int t=1;
    //cin>>t;
    fol(i,0,t) { tejas_919(i+1); }
    end_routine();
    if(localsys) system("pause");
}