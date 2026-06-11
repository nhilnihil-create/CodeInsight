#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    ll N,L;
    cin >> N >> L;
    ll A[N];
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    ll lastKnot = -1;
    for(int i = 1; i < N; i++){
        if(A[i - 1] + A[i] >= L){
            lastKnot = i;
        }
    }
    if(lastKnot != -1){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
        return 0;
    }
    for(int i = 1; i < lastKnot; i++){
        cout << i << endl;
    }
    for(int i = N - 1; i > lastKnot; i--){
        cout << i << endl;
    }
    cout << lastKnot << endl;
}
