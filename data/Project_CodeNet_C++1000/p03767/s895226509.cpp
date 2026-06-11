#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int N;
    cin >> N;

    vector<ll> a(3*N);
    for (int i=0; i<3*N; i++){
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());

    ll sum = 0;
    int cnt = 0;
    for (int i=3*N-2; i>=0; i -= 2){
        sum += a.at(i);
        cnt++;

        if (cnt >= N) break;
    }

//    cout << cnt << endl;    // debug
    cout << sum << endl;
    return 0;
}
