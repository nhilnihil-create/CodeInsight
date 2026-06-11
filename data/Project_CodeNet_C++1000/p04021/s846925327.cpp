#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N;
    cin >> N;
    vector<P> vec(N);
    for(int i = 0;i < N;i++) {
        int A;
        cin >> A;
        vec.at(i) = P(A,i);
    }
    sort(vec.begin(),vec.end());
    int A = 0;
    int B = 0;
    for(int i = 0;i < N;i++) {
        if(i % 2 == 0) {
            if(vec.at(i).second % 2 == 1) {
                A++;
            }
        }
        else {
            if(vec.at(i).second % 2 == 0) {
                B++;
            }
        }
    }
    cout << A << endl;
}