#include <cstdio>
#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <numeric>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <stack>

using namespace std;

#define INFint (1<<30)
#define BOUND 27182818284
#define MAT 2

typedef long long ll;
typedef long long int lli;
typedef pair<ll, ll> P;

ll MOD = 1000000007;
const ll INF = (1ll<<60);
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i=int(a);i<int(b);++i)

template<class T>
bool umax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool umin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

// gcd
template<typename T>
T gcd(T a, T b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int findGCD(vector<int> arr) {
    int result = arr[0];
    for (auto a: arr) {
        result = gcd(a, result);
    }
    return result;
}

template<typename T>
T lcm(T m, T n) {
    // 引数に0がある場合は0を返す
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    fill((T *) array, (T *) (array + N), val);
}


int dx[5] = {1, 0, -1, 0};
int dy[5] = {0, 1, 0, -1};

// v.front() = -BOUND;
// v.back() = BOUND;

//struct edge{
//    int cost, to;
//
//    edge(int in_cost, int in_to){
//        cost=in_cost;
//        to=in_to;
//    }
//    bool operator<(const edge &a) const
//    {
//        return cost > a.cost;
//    }
//};

int main() {
    int N; cin >> N;
    string S; cin >> S;
    // true -> sheep, false -> wolf
    vector<bool> label(N+2);

    for(int i=0; i<(1<<2); i++){
        label[0] = ((i>>1) & 1)==1;
        label[1] = ((i>>0) & 1)==1;

        for(int j=1; j<N; j++){
            if( (S[j]=='o') && label[j]){ // S && o
                label[j+1] = label[j-1];

            }else if( (S[j]=='o') && !label[j]){ // W && o
                label[j+1] = !label[j-1];

            }else if( (S[j]=='x') && label[j]){ // S && x
                label[j+1] = !label[j-1];

            }else if( (S[j]=='x') && !label[j]){ // W && x
                label[j+1] = label[j-1];

            }
        }
        if(label[0]!=label[N])
            continue;

        if(
                (label[0] && (S[0]=='o') && (label[N-1]==label[1])) ||
                (label[0] && (S[0]=='x') && (label[N-1]!=label[1])) ||
                (!label[0] && (S[0]=='o') && (label[N-1]!=label[1])) ||
                ( !label[0] && (S[0]=='x') && (label[N-1]==label[1]))
        ){
            for(int j=0; j<N; j++){
                cout << (label[j] ? 'S' : 'W');
            }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
