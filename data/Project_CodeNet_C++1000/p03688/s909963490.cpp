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
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(a[N - 1] - a[0] >= 2){
        cout << "No" << endl;
        return 0;
    }

    if(a[N - 1] == a[0]){
        if(a[0] == N - 1){
            cout << "Yes" << endl;
        }else{
            if(a[0] * 2 <= N){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
        return 0;
    }

    ll color = a[N - 1];
    ll enableCol = color;
    ll tmp = 0;
    for (int i = 0; i < N; ++i) {
        if(a[i] != color){
            enableCol--;
        }else{
            tmp++;
        }
    }
    if(enableCol <= 0){
        cout << "No" << endl;
        return 0;
    }
    if(enableCol * 2 <= tmp){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



}
