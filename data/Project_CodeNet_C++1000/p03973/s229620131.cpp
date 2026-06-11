#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    int N;
    cin >> N;
    ll a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    ll ans = 0;
    ll mn = 0;
    for(int i = 0; i < N; i++){
        ll div = mn + 1;
        ans += (a[i] - 1) / div;

        if(i == 0) mn = 1;
        else if((a[i] - 1) / div == 0){
            mn = max(mn, a[i]);
        }
    }

    cout << ans << endl;
    return 0;
}
