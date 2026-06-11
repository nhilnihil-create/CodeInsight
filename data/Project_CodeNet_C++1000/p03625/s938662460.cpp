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
        int a;
        cin >> a;
        M[a]++;
    }

    ll Big=0, Small=0;
    for(auto m:M) {
        if(m.second >= 4) {
            Big = m.first, Small = m.first;
        }
        else if(m.second >= 2) {
            swap(Big, Small);
            Big = m.first;
        }
    }
    cout << Big * Small << endl;
}