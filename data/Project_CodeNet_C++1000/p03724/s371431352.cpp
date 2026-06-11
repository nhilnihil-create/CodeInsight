#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> vec(N);
    for(int i = 0;i < M;i++) {
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        vec.at(A)++;
        vec.at(B)++;
    }
    bool ret = true;
    for(int i = 0;i < N;i++) {
        if(vec.at(i) % 2 != 0) {
            ret = false;
        }
    }
    if(ret == true) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}