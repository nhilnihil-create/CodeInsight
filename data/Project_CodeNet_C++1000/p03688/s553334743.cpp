#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 998244353;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    sort(vec.begin(),vec.end());
    if(vec.at(N - 1) - vec.at(0) >= 2) {
        cout << "No" << endl;
    }
    else if(vec.at(N - 1) == vec.at(0)) {
        if(2 * vec.at(0) <= N || vec.at(0) == N - 1) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        int cnt = 0;
        for(int i = 0;i < N;i++) {
            if(vec.at(i) == vec.at(0)) {
                cnt++;
            }
        }
        if(cnt <= vec.at(0) && 2 * (vec.at(N - 1) - cnt) <= N - cnt) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}