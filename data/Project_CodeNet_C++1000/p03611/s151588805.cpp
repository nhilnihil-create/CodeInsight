#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    int N, count = 0, max_count = 0;
    cin >> N;
    vector<int> a(100001);
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    for(int i=1; i<a.size()-1; i++) {
        count = a[i-1]+a[i]+a[i+1];
        max_count = max(max_count, count);
    }
    cout << max_count << endl;

}