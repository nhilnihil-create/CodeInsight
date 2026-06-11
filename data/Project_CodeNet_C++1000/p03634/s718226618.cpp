/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    WRITER:kakitamasziru/OxOmisosiru
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG //FOR THE DEBUG! COMMENT OUT THIS WHEN SUBMITTING!
#endif
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <iomanip>
#include <limits>//setprecision
//#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
//#include <unordered_map> // unordered_map
//#include <unordered_set> // unordered_set
#include <bitset> // bitset
//#include <cctype> // isupper, islower, isdigit, toupper, tolower
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1001001001001001;
long long MOD;
typedef pair<long long,long long> P;
//NのM乗を求める(繰り返し二乗法)
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}
long long nCr(long long n, long long r) {
    long long A = 1, B = 1;
    //Aが分子Bが1/r!
    for (long long i = n - r + 1; i <= n; i++) {
        A = A * i % MOD;
    }
    for (long long i = 1; i <= r; i++) {
        B = B * i % MOD;
    }
    B = mod_pow(B, MOD - 2);
    B %= MOD;
    //Bは割るのではなく掛ける
    return (A * B) % MOD;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
 
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

long long A,B;

bool ok(long long key,long long index){
    string S = to_string(index);
    long long nagasa = S.size();
    if(index*A+nagasa*B > key) return true;
    else if(index*A+nagasa*B <= key) return false;
}

long long binary_search(long long key,long long size){
    //left,right,midはいずれもindex
    long long left = -1,right = size;
    while(right - left > 1){
        long long mid = left + (right-left)/2;
        long long hantei = ok(key,mid);
        if(hantei) right = mid;
        else left = mid;
    }
    if(left == -1)return 0;
    return left;
}

long long DfromK[100002];
bool seen[100002];
vector<vector<P>> edge(100002);

void dfs(int from,int to,long long cost){
    DfromK[from] = min(DfromK[from],cost);
    for(auto V : edge.at(from)){
        //親に戻らないようにする
        if(V.first == to) continue;
        dfs(V.first,from,cost+V.second);
    }
}

int main() {
    int N;cin >> N;
    for(int i = 0;i<N-1;i++){
        int a,b,c;cin >> a >> b >> c;
        a--;b--;
        edge.at(a).push_back(make_pair(b,c));
        edge.at(b).push_back(make_pair(a,c));
    }
    for(int i = 0;i<100002;i++)DfromK[i] = INF;

    int Q,K;cin >> Q >> K;K--;
    DfromK[K] = 0;

    dfs(K,100001,0);

    vector<long long> ans(Q);

    for(int i = 0;i<Q;i++){
        int from,to;cin >> from >> to;from--;to--;
        ans.at(i) = DfromK[from]+DfromK[to];
    }

    for(int i = 0;i<Q;i++) cout << ans.at(i) << endl;

    return 0;

    // PLEASE GIVE ME THE "ACCEPTED" !
}
