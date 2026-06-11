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
    int N, T;
    cin >> N >> T;
    vector<int> as(N, 0);
    int a_min = 1e9;
    int d = 0;
    int cnt = 0;
    rep(i, N){
        int a;
        cin >> a;
        a_min = min(a_min, a);
        if(d == a - a_min){
            cnt ++;
        }
        if(d < a - a_min){
            cnt = 1;
            d = a - a_min;
        }
    }
    cout << cnt << endl;
    return 0;
}
