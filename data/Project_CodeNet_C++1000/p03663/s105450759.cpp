#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
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
template <ostream& out = cout, class... T> void prints(T&&...){ }
template <ostream& out = cout, class... T> void printd(T&&...){ }
template <ostream& out = cout, class... T> void printde(T&&...){ }
template <ostream& out = cout, class... T> void printb(T&&...){ }
template <ostream& out = cout, class... T> void printArr(T&&...){ }
#endif

int main(){
    // stringstream ans;
    ll num = 0;
    int ke = 0;
    for(int i = 0; i <= 9; i++){
        ke = i;
        ll a = pow(10ll, i);
        prints<cerr>('?', a);
        cout << "? " << a << endl;
        char ret; cin >> ret;
        if(ret == 'Y'){
        }else{
            break;
        }
        if(i == 9){
            for(int i = 0; i <= 11; i++){
                ke = i;
                ll a = pow(10ll, i + 1) - 1;
                cout << "? " << a << endl;
                char ret; cin >> ret;
                if(ret == 'Y'){
                    ke++;
                    break;
                }else{
                }
            }
        }
    }
    ke--;
    for(int i = ke; i >= 0; i--){
        ll l = 0, r = 9;
        while(l < r){
            // ll cand = (l + r + 1) / 2;
            ll cand = (l + r) / 2;
            // ll a = (cand + 1) * 10000000000 - 1;//, b = cand * 10000000000 - 1;
            ll a = num * pow(10ll, i + 2) + (cand + 1) * pow(10ll, i + 1) - 1;//, b = cand * 10000000000 - 1;
            // ll a = num * pow(10ll, i + 1) + (cand + 1) * pow(10ll, i + 0) - 1;//, b = cand * 10000000000 - 1;
            if(cand == 0 && ke == i){
                // a++;
                // a /= 10;
                l = 1;
                break;
            }
            // ll a = num * pow(10ll, i + 2) + cand * pow(10ll, i + 1);//, b = cand * 10000000000 - 1;
            // ll a = cand;//, b = cand * 10000000000 - 1;
            if(a == 0){
                cout << "! " << 1 << endl;
                return 0;
            }
            prints<cerr>('?', a);
            cout << "? " << a << endl;
            printde(l, r, num);
            char ret; cin >> ret;
            if(ret == 'Y'){
                // r = cand - 1;
                // if(cand == 0){
                //     a--;
                //     a /= 10;
                //     cout << "? " << a << endl;
                //     cin >> ret;
                //     if(ret == 'N'){
                //         l = cand + 1;
                //         goto hoge;
                //     }
                // }
                r = cand;
            }else{
                // l = cand;
                l = cand + 1;
            }
// hoge: ;
        }
        // ans << l;
        num = num * 10 + l;
    }
    // cout << "! " << stoi(ans.str()) << '\n';
    // cout << "! " << num + 1 << endl;
    // cout << "! " << num << endl;
    cout << "! " << (num ? num : 1) << endl;
    return 0;
}
