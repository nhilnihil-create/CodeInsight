#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
template <class... T> void printd(T&&...){ }
#endif

int least[100100];
int calcLeast(vector<int>& xs, int idx){
    if(idx == 0){
        least[0] = 0;
        return 0;
    }
    return least[idx] = max(calcLeast(xs, idx - 1), max(0, idx - (xs[idx - 1] + 1) / 2));
}

bool isPossible(vector<int>& xs, int num){
    prints(num);
    while(num > 0){
        num--;
        while(num >= 0 && xs[num] == 0){
            num--;
        }
        int cnt = 0;
        for(int i=0;i<=num;i++){
            cnt += (bool)xs[i];
        }
        if(num >= 0 && (xs[num] + 1) / 2 < cnt){
            prints(xs, num, cnt);
            return false;
        }
    }
    return true;
}

int main(){
    int n; cin >> n;
    vector<int> xs(n);
    for(int i=0;i<n;i++){
        cin >> xs[i];
    }
    calcLeast(xs, n - 1);
    ll ans = 1;
    for(int i=0;i<n;i++){
        // rprint::print(least[i]);
        ans = ans * (i + 1 - least[i]) % M;
    }
    cout << ans << '\n';
    return 0;
    // vector<int> pts(n);
    // iota(pts.begin(), pts.end(), 0);
    // int ans = 0;
    // do{
    //     bool ok = true;
    //     auto _xs = xs;
    //     for(int num : pts){
    //         if(!isPossible(xs, num)){
    //             ok = false;
    //             // prints(xs, num);
    //             break;
    //         }
    //         xs[num] = 0;
    //     }
    //     ans += ok;
    //     xs = _xs;
    // }while(next_permutation(pts.begin(), pts.end()));
    // cout << ans << '\n';
    // return 0;
}
