#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int n;
    cin >> n;
    
    vec<int> a(n);
    rep(i, n) cin >> a[i];

    deque<int> q;
    rep(i,n){
        if(i%2==1){
            q.push_front(a[i]);
        } else {
            q.push_back(a[i]);
        }
    }

    if(n%2==1){
        rep(i,n){
            int a = q.back();
            q.pop_back();
            cout << a << " ";
        }
    } else {
        rep(i,n){
            int a = q.front();
            q.pop_front();
            cout << a << " ";
        }
    }
    cout << endl;
}
