#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<ll> deq;
    int reverse = 0;

    rep(i,n) {
        ll a;
        cin >> a;
        if(reverse) deq.push_front(a);
        else deq.push_back(a);

        reverse ^= 1;
    }

     reverse = n % 2;

    if(reverse){
        rep(i,n) {
            cout << deq.back() << " ";
            deq.pop_back();
        }
    }else{
        rep(i,n) {
            cout << deq.front() << " ";
            deq.pop_front();
        }
    }


    return 0;
}