#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>
#include <set>

using namespace std;

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ; //何もしない文
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    string S; cin >> S;

    string cand[4];
    cand[0] += "SS";
    cand[1] += "SW";
    cand[2] += "WS";
    cand[3] += "WW";


    REP(i,4){
        FOR(j,1,N-1){
            if(cand[i][j] == 'S' && S[j] == 'o'){
                cand[i] += cand[i][j-1];
            }

            if(cand[i][j] == 'S' && S[j] == 'x'){
                char tmp = cand[i][j-1];
                if(tmp == 'S') cand[i] += 'W';
                else cand[i] += 'S';
            }

            if(cand[i][j] == 'W' && S[j] == 'o'){
                char tmp = cand[i][j-1];
                if(tmp == 'S') cand[i] += 'W';
                else cand[i] += 'S';
            }

            if(cand[i][j] == 'W' && S[j] == 'x'){
                cand[i] += cand[i][j-1];
            }
        }

        bool ok = 1;
        // check

        if(cand[i][N-1] == 'S'){
            if(S[N-1] == 'o'){if(cand[i][N-2] != cand[i][0]) ok = 0;}
            else if(cand[i][N-2] == cand[i][0]) ok = 0;
        }
        else{
            if(S[N-1] == 'o'){if(cand[i][N-2] == cand[i][0]) ok = 0;}
            else if(cand[i][N-2] != cand[i][0]) ok = 0;
        }

        if(cand[i][0] == 'S'){
            if(S[0] == 'o'){if(cand[i][N-1] != cand[i][1]) ok = 0;}
            else if(cand[i][N-1] == cand[i][1]) ok = 0;
        }
        else{
            if(S[0] == 'o'){if(cand[i][N-1] == cand[i][1]) ok = 0;}
            else if(cand[i][N-1] != cand[i][1]) ok = 0;
        }

        if(ok){
            cout << cand[i] << endl;
            return 0;
        }


    }
    cout << "-1" << endl;


}