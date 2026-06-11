#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll dis = llabs(a-b);
    n -= 1;
    if (dis > n*d) {
        cout << "NO" << endl;
    } else if (dis >= n*c && dis <= n*d) {
        cout << "YES" << endl;
    } else {
        ll min_diff = llabs(c-d);
        ll use_low = dis / c;
        ll remain_dis = dis % c;
        ll remain_step = n - use_low;
        // printf("remain step = %lld, remain_dis = %lld\n",
        //        remain_step, remain_dis);
        bool odd_time = false;
        if (remain_step % 2 == 1) {
            remain_step -= 1;
            remain_dis = c - remain_dis;
            odd_time = true;
        }
        //printf("mid_diff %lld\n", min_diff);
        //printf("remain_dis %lld \n", c-remain_dis);
        //printf("remain step = %lld, remain_dis = %lld\n",
            //remain_step, remain_dis);
        ll max_bias = ((remain_step / 2)) * min_diff;
        if (odd_time == false)
            max_bias += use_low * min_diff;
        // cout << max_bias << endl;
        if (max_bias >= remain_dis) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}


