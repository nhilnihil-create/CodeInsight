#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>

#ifdef _MSC_VER
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef long long LL;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD=(LL)1e9+7;
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

#define INF 1LL << 50

vector<vector<LL>>res;
LL calc(){
    vector<LL>vec;
    REP(i,50)vec.PB(50);
    while(vec.back()>=50){
        REP(i,49)vec[i]++;
        vec[49]-=50;
        SORT(vec);
        res.PB(vec);
    }
    //cout<<SZ(res)<<endl;
}

int main(){
    LL K;
    cin>>K;
    LL d =K/50LL;
    int d2=K%50;
    calc();
    cout<<50<<endl;
    REP(i,50){
        if(d2!=0)cout<<d+res[49-d2][i]<<" ";
        else cout<<49LL+d<<" ";
    }
    cout<<endl;
    return 0;
}
