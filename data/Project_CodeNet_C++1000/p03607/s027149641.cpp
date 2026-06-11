#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    int N;
    cin >> N;
    map<int, int> M;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        M[x]++;
    }
    int count = 0;
    for(auto m:M) {
        if(m.second % 2 == 1) {
            count++;
        }
    }
    cout << count << endl;
}