#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i, N){
        cin >> p[i];
    }
    int ans = 0;
    rep(i, N){
        if(p[i] == i + 1 && i < N - 1){
            swap(p[i], p[i + 1]);
            ans ++;
        }
        if(p[i] == i + 1 && i == N - 1){
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}
