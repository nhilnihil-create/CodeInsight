#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

ll N;
ll A[100000];

template <typename T>
T gcd(T a, T b){
    if(a < b) swap(a, b);
    while(b != 0){
        T tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

ll cntOdd(){
    ll ans  = 0;
    for(ll i = 0; i < N; i++){
        if(A[i]%2 == 1) ans++;
    }
    return ans;
}

ll cntRem(){
    ll ans  = 0;
    for(ll i = 0; i < N; i++){
        ans += (A[i]-1);
    }
    return ans;
}

ll gcd_all(){
    ll ans = gcd<ll>(A[0], A[1]);
    for(ll i = 2; i < N; i++){
        ans = gcd<ll>(ans, A[i]);
    }
    return ans;
}

ll oddIdx(){
    for(ll i = 0; i < N; i++){
        if(A[i]%2 == 1)return i;
    }
}

void process(){
    ll g = gcd_all();
    for(ll i = 0; i < N; i++) A[i] /= g;
}

bool oneExists(){
    for(ll i = 0; i < N; i++){
        if(A[i] == 1) return true;
    }
    return false;
}

string ans;

void judge(ll cur){
    // cout << "judge()" << endl;
    // for(ll i = 0; i < N; i++) cout << A[i] << ' ';
    // cout << endl;
    ll rem = cntRem();
    if(oneExists()){
        if(rem%2 == 1){
            ans = cur == 0 ? "First" : "Second";
        }else{
            ans = cur == 0 ? "Second" : "First";
            return;
        }
    }
    if(rem%2 == 1){
        ans = cur == 0 ? "First" : "Second";
        return;
    }
    if(cntOdd() >= 2){
        ans = cur == 0 ? "Second" : "First";
        return;
    }
    ll idx = oddIdx();
    A[idx]--;
    process();
    judge(cur^1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N;
    for(ll i = 0; i < N; i++) cin >> A[i];
    if(N == 1) {
        if(A[0] == 1){
            cout << "Second" << endl;
        }else{
            cout << "First" << endl;
        }
        return 0;
    }
    judge(0);
    cout << ans << endl;
}