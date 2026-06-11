#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007
#define F "test.txt"

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    ll N, L;
    cin >> N >> L;
    int flag = -1;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    rep(i,N-1){
        if(a[i] + a[i+1] >= L) flag = i;
    }
    if(flag != -1){
        cout << "Possible" << endl;
        for(int i = 1; i <= N-1; i++){
            if(i == flag + 1) break;
            cout << i << endl;
        }
        for(int i = N-1; i >= 1; i--){
            if(i == flag + 1) break;
            cout << i << endl;
        }
        cout << flag+1 << endl;
    }
    else cout << "Impossible" << endl;
}