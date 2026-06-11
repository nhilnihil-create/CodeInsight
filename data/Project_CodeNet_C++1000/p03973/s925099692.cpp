#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <limits.h>
#include <utility>
#include <stack>

using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> T;

int main(){
    ll N;
    cin >> N;
    ll a[101000];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    ll bMax = 1;
    ll res = a[0] - 1;
    for(int i = 1; i < N; i++){
        if(bMax + 1 >= a[i]){
            bMax = max(bMax, a[i]);
            continue;
        }
        int x = (a[i] - 1) / (bMax + 1);
        res += x;
    }
    cout << res << endl;


    return 0;
}