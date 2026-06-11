#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    a.at(0) = 1;
    b.at(N - 1) = 1;
    for(int i = 0;i < N - 1;i++) {
        a.at(i + 1) = a.at(i) + 20001;
    }
    for(int i = N - 1;i >= 1;i--) {
        b.at(i - 1) = b.at(i) + 20001;
    }
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        int A;
        cin >> A;
        A--;
        vec.at(i) = A;
    }
    for(int i = 0;i < N;i++) {
        a.at(vec.at(i)) += i;
    }
    for(int i = 0;i < N;i++) {
        cout << a.at(i) << " ";
    }
    cout << endl;
    for(int i = 0;i < N;i++) {
        cout << b.at(i) << " ";
    }
    cout << endl;
}