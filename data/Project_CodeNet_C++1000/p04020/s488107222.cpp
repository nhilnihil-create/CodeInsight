#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
#define coutd(i) cout << std::fixed << std::setprecision(i)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Set = std::set<T>;
template<class T, class U>
using Map = std::map<T, U>;

template<class T>
using Graph = vector<vector<T>>;

const int INT_BIG = 1<<28;

int main() {
    int N;
    cin >> N;

    vll As(N);
    rep(i, N) {
        cin >> As[i];
    }

    ll sum = 0;
    rep(i, N) {
        sum += As[i] / 2;
        As[i] %= 2;

        if (i != N - 1) {
            if (As[i] == 1 && As[i+1] > 0) {
                sum++;
                As[i]--;
                As[i+1]--;
            }
        }
    }
    cout << sum << endl;
}