#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001


int main() {
    int N; cin >> N;
    vector<ll> C(N+1);
    ll sum = 0;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        C[i+1] = C[i] + a;
        sum += a;
    }
    
    ll mn = 1LL << 60;
    for(int i=1; i<N; i++){
        mn = min(mn, abs(C[i]-(sum-C[i])));
    }
    
    cout << mn << endl;
    return 0;
}

