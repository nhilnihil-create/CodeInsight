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
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 1000000000000000
#define MAX 200001
#define MOD 1000000007  

int main(){
    ll N, x;
    ll ans = INF;
    cin >> N >> x;
    vector<ll> a(N);
    vector<ll> b(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++){
        ll res = 0;
        for(int j = 0; j < N; j++){
            if(i == 0) b[j] = a[j];
            else if(j - i < 0){
                b[j] = min(b[j], a[N - i + j]);
            }
            else if(j - i >= 0){
                b[j] = min(b[j], a[j - i]);
            }
        }
        for(int k = 0; k < N; k++){
            res += b[k];
        }
        res += i * x;
        ans = min(ans, res);
    }
    cout << ans << endl;
}