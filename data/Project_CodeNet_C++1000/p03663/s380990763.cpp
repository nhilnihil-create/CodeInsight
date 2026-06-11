/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#ifdef ARYANC403
    #include "/home/aryan/codes/PastCodes/template/header.h"
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    #pragma GCC optimize ("-ffloat-store")
    #include<iostream>
    #include<bits/stdc++.h>
    #define dbg(args...)
#endif

using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
// #define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    lli ans;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

bool query(lli x,bool fl=true)
{
    if(fl)
        x*=1e9;
    if(x==0)
        return true;
#ifdef ARYANC403
    cout<<"? "<<x<<endl;
    // if(x==0)
    // {
    //     dbg(x,ans,(x<=ans&&to_string(x)<=to_string(ans))||(x>ans&&to_string(x)>to_string(ans)));
    // }
    return (x<=ans&&to_string(x)<=to_string(ans))||(x>ans&&to_string(x)>to_string(ans));
#else
    cout<<"? "<<x<<endl;
    cin>>s;
    return s=="Y";
#endif
}

void solve1()
{
    exit(0);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

#ifdef ARYANC403
    dbg("inp",ans)
    // cin>>ans;
    dbg(ans);
#endif
// ans=12311;
// for(ans=1;ans<=1e9;ans++)
{
    lli cur=0;
    for(lli i=1;i<=9;++i)
    {
        lli l=-1,r=10;
        while(r-l>1)
        {
            lli m=(l+r)/2;
            if(query(cur*10+m))
                r=m;
            else
                l=m;
        }

        if(l==9)
        {
            cur=cur*10+l;
            continue;
        }

        if(r==0)
        {
            cur=cur*10;
            continue;
        }

        if(i==1&&r==1)
        {
            cur=cur*10+1;
            continue;
        }

        // dbg(i,cur,ans,l,r);
        // dbg(query(cur*10+l),query(cur*10+r));
        // dbg(query(cur*10+l,false),query(cur*10+r,false));
        if(query(cur*10+l,false)&&query(cur*10+r,false))
        {
            cur=cur*10+r;
            break;
        }
        cur=cur*10+l;
    }

    if(cur==0)
        cur++;
    while(cur<1e11&&query(cur*10-1,false))
        cur*=10;
    if(cur!=1)
    {
        if(cur>1e10)
            cur=1;
    }
    else
    {
        while(!query(cur*10-1,false))
            cur*=10;
        // while(cur<1e11)
        // {
        //     dbg(cur,query(cur,false));
        //     dbg(cur,);
        //     cur*=10;
        // }
    }

    // if(ans!=cur)
    // {
    //     dbg(cur,ans);
    // }

    if(ans%1000000==0)
    {
        dbg("upto",ans);
    }
    dbg(cur,ans);
    // assert(cur==ans);
    cout<<"! "<<cur<<endl;
}
}   aryanc403();
    return 0;
}
