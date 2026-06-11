#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    bool issame = true;
    for(int i = 0;i < N - 1;i++) {
        if(vec.at(i) != vec.at(i + 1)) {
            issame = false;
        }
    }
    if(issame == true) {
        if(vec.at(0) == N - 1 || 2 * vec.at(0) <= N) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        sort(vec.begin(),vec.end());
        if(vec.at(N - 1) - vec.at(0) >= 2) {
            cout << "No" << endl;
        }
        else {
            int alone = 0;
            for(int i = 0;i < N;i++) {
                if(vec.at(i) == vec.at(0)) {
                    alone++;
                }
            }
            if(alone < vec.at(N - 1) && 2 * (vec.at(N - 1) - alone) <= (N - alone)) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}