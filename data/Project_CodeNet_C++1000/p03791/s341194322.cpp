#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;
#define MOD 1000000007

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> x(N);
    vector<int> a(N, 0);
    for(int i=0; i<N; i++) cin >> x[i];
    x[0] = 1;
    if(x[1] > 2) x[1] = 3;
    for(int i=2; i<N; i++){
        if(x[i-1] == x[i-2] + 1 && a[i-1] == a[i-2]){
            x[i] = x[i-1] + 1;
            a[i] = a[i-1] + 1;
        }
        else{
            x[i] = min(x[i-1] + 2, x[i]);
            a[i] = a[i-1];
        }
    }

    vector<unsigned long long> c(N, 0);
    for(auto i : a) c[i]++;

    unsigned long long ans = 1;
    vector<unsigned long long> d(N, 0);
    d[0] = c[0];
    for(int i=1; i<N; i++)
        d[i] = d[i-1] + c[i] - 1;

    for(int i=0; i<N; i++){
        ans *= d[i];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
