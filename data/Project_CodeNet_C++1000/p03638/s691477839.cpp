//include
//------------------------------------------
#include <bits/stdc++.h>
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
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const long long INF = 1000000007;
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
// chmax chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int done[100][100];

char next_(int *i, int *j, char dire, int H, int W){
    if(dire=='u'){
        if(*i-1>=0 && done[*i-1][*j]==0){*i-=1; done[*i][*j]=1; return 'u';}
        else{*j+=1; done[*i][*j]=1; return 'r';}
    } else if(dire=='r'){
        if(*j+1<W && done[*i][*j+1]==0){*j+=1; done[*i][*j]=1; return 'r';}
        else{*i+=1; done[*i][*j]=1; return 'd';}
    } else if(dire=='d'){
        if(*i+1<H && done[*i+1][*j]==0){*i+=1; done[*i][*j]=1; return 'd';}
        else{*j-=1; done[*i][*j]=1; return 'l';}
    } else {
        if(*j-1>=0 && done[*i][*j-1]==0){*j-=1; done[*i][*j]=1; return 'l';}
        else{*i-=1; done[*i][*j]=1; return 'u';}
    }
}
int main(void){
    int H,W,N; cin >> H >> W >> N;
    int a[N]; REP(i,N) cin >> a[i];
    REP(i,H)REP(j,W) done[i][j] = 0;
    done[0][0] = 1;
    int c[H][W];

    int ptr=0;
    int i=0,j=0;
    char dire='r';
    REP(k,H*W){
        c[i][j] = ptr+1;
        a[ptr]--;
        if(a[ptr] == 0) ptr++;
        dire = next_(&i, &j, dire, H, W);
    }

    REP(i,H){
        REP(j,W){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}