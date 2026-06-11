#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;

int main() {
    int n; cin >> n;
    deque<int> deq;
    if(n % 2==0){
        for(int i = 0;i < n;i++){
            int x ; cin >> x;
            if(i%2 ==0){
                deq.push_back(x);
            }else{
                deq.push_front(x);
            }
        }
    }else{
        for(int i = 0;i < n;i++){
            int x ; cin >> x;
            if(i%2 ==0){
                deq.push_front(x);
            }else{
                deq.push_back(x);
            }
        }
    }
    for(auto m:deq){
        cout << m << " ";
    }
}


