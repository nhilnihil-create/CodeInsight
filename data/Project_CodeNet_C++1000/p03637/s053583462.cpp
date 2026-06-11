#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    
    int x2 = 0;
    int x4 = 0;
    vec<int> a(N);
    rep(i, N){
        int a;
        cin >> a;
        if(a%4 ==0){
            ++x4;
            continue;
        } else if(a%2 == 0){
            ++x2;
            continue;
        }
    } 
    if(N%2 == 1) --N;
    bool c = N-(x4*2) -x2 <= 0;
    cout << (c?"Yes": "No") << endl;
}
