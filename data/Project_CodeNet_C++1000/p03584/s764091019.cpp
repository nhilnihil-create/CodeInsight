#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> a, b;

long long f(int msk){
    long long res = 0;
    for(int i=0;i<n;i++){
        if((a[i]&(~msk)) == 0) res += b[i];
    }
    return res;
}

int main(void){
    cin >> n >> k;
    a.assign(n, 0);
    b.assign(n, 0);
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];

    long long ans = f(k);
    for(int i=0;i<30;i++){
        if(((k>>i)&1) == 1){
            int msk = ((k>>i) << i) - 1;
            long long t = f(msk);
            if(ans < t) ans = t;
        }
    }
    cout << ans << endl;
}
