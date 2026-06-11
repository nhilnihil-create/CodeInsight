#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    map<int, int> m;
    vector<ll> v;
    for (int i = 0; i < N; i++){
        int a; cin >> a;
        m[a]++;
        if(m[a]==2){
            m[a] = 0;
            v.push_back(a);
        }
    }

    if(v.size()<2){
        cout << 0 << endl;
        return 0;
    }
    sort(v.begin(), v.end(), greater<int>());
    cout << v[0] * v[1] << endl;
}