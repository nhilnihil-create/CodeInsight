#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // setprecision
#include <complex> // complex
#include <math.h> 
#include <climits> 
#include <assert.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr ll mod = 1000000007;
constexpr ll mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[8] = {1, 0, -1, 0,1,1,-1,-1};
const int dy[8] = {0, 1, 0, -1,1,-1,1,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------

int main(){
    string S;
    cin >> S;
    int N = S.size();
    int l = N;
    for(int i=2; i<N; i++){
        if(S[i-2] != S[i]){
            l = i;
            break;
        }
    }    
    int r;
    for(int i=N-3; i>=0; i--){
        if(S[i] != S[i+2]){
            r = i;
            break;
        }
    }
    if(l == r && l!=0){
        if(S[l-1] == S[l+1]){
            cout << "Second\n";
        }else{
            cout << "First\n";
        }
        return 0;
    }
    if((N-2 - (S[0]==S[N-1]))%2){
        cout << "First\n";
    }else{
        cout << "Second\n";
    }
    return 0;
}