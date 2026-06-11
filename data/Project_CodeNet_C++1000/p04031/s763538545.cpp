#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    ll min_cost = INF;

    for(int i=-100; i<=100; i++) {
        ll cost=0;
        for(int j=0; j<N; j++) {
            cost += pow((A[j]-i), 2);
        }
        min_cost = min(cost, min_cost);
    }
    cout << min_cost << endl;
}