#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;
typedef int64_t ll;


int main() {
    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    for (int i = 0; i < T; i++){
        cin >> a.at(i);
    }
    sort(rALL(a));
    if (K % 2 == 0){
        if (a.at(0) * 2 <= K){
            cout << 0 << endl;
        }
        else {
            cout << 2 * a.at(0) - K - 1<< endl;
        }
    }
    else {
        if (a.at(0) * 2 - 1 <= K){
            cout << 0 << endl;
        }
        else {
            cout << 2 * a.at(0) - K << endl;
        }
    }
}
