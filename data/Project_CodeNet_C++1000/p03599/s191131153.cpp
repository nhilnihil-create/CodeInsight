#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define VIN(v) for(auto&elem_: (v) )cin>>elem_
#define VOUT(v, sep) for(_loop_int idx=0; idx<(_loop_int)v.size(); idx++) {cout<<v[idx]; if(idx<v.size()-1) cout<<sep;} cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(debugidx,v.size())cout<<" "<<v[debugidx];cout<<endl
#define DEBUG_ARR(v,n) cout<<#v<<":";REP(debugidx,n)cout<<" "<<v[debugidx];cout<<endl

const ll MOD = 1000000007ll;
const int IINF = numeric_limits<int>::max()/2-1;
const ll LINF = numeric_limits<ll>::max()/2-1;

template<class T> inline bool chmin(T& a, const T b) { if (a>b) { a=b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T b) { if (a<b) { a=b; return true; } return false; }



int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int w1, w2, s1, s2, melt, limit;
    //100gあたりmeltグラム溶けます。ビーカーには水+砂糖でlimitグラムまで入ります。
    //w1<w2
    //s1<s2
    cin>>w1>>w2>>s1>>s2>>melt>>limit;

    vi w;

    for(int i=0; i<=limit; i+=w2*100){
        w.emplace_back(i);
        for(int j=i+w1*100; j<=limit; j+=w1*100){
            w.emplace_back(j);
        }
    }
    sort(ALL(w));
    w.erase(unique(ALL(w)), w.end());
    w.erase(w.begin());//0を消す

    vi s;

    for(int i=0; i<=limit; i+=s2){
        s.emplace_back(i);
        for(int j=i+s1; j<=limit; j+=s1){
            s.emplace_back(j);
        }
    }
    sort(ALL(s));
    s.erase(unique(ALL(s)), s.end());

    double mx = -5.f;
    pii ans = pii(0,0);
    REP(i,w.size()){
        REP(j,s.size()){
            //DEBUG2(w[i], s[j]);
            if( (w[i]/100)*melt < s[j] )  continue;
            if( w[i]+s[j] > limit )      continue;

            double pertmp = (100.f*s[j]) / ((double)w[i]+s[j]);
            //DEBUG2(mx, pertmp);
            if(chmax(mx,pertmp)){
                ans.first = w[i];
                ans.second = s[j];
            }
        }
    }

    cout << ans.first+ans.second << " " << ans.second << endl;
    return 0;
}