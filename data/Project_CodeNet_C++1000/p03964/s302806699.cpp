#include<bits/stdc++.h>
using namespace std;



#define int long long

// int euclidean_gcd(unsigned a, unsigned b) {
//   while(1) {
//     if(a < b) swap(a, b);
//     if(!b) break;
//     a %= b;
//   }
//   return a;
// }

signed main(void){
    int n; cin >> n;
    int t,a;
    cin >> t >> a;
    for(int i=1;i<n;i++){
        int tmp_t,tmp_a; cin >> tmp_t >> tmp_a;
        int x,y;
        x = (t+tmp_t-1)/tmp_t;
        y = (a+tmp_a-1)/tmp_a;
        if(x < y) t = tmp_t*y,a = tmp_a*y;
        else t = tmp_t*x, a = tmp_a * x;
    }
    cout << t+a << endl;
    return 0;
}