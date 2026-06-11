#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll ZERO = 0;
const ll INF = 1e14;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;

int main() {
    string S;
    cin >> S;
    int K;
    cin >> K;
    vector<int> vec(S.size());
    for(int i = 0;i < S.size();i++) {
        if(S.at(i) == 'a') {
            vec.at(i) = 0;
        }
        else {
            vec.at(i) = 26 - (S.at(i) - 'a');
        }
    }
    for(int i = 0;i < S.size();i++) {
        if(K >= vec.at(i)) {
            S.at(i) = 'a';
            K -= vec.at(i);
        }
    }
    S.at(S.size() - 1) = (S.at(S.size() - 1) - 'a' + K) % 26 + 'a';
    cout << S << endl;
}