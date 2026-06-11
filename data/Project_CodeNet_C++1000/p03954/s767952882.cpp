#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N;
ll a[200010];
ll test[200010];
ll test2[200100];

void query(int from, int to) {
    if(from >= to) return;
    //cerr << "query " << from << " " << to << endl;
    int before = from;
    while((test[before] != 1) || (test[before+1] != 1)) {
        before++;
        if(before == to) return;
    }
    int after = to;
    while((test[after] != 1) || (test[after-1] != 1)) after--;
    //cerr << from << " " << before << " " << after << " "<< to << endl;
    for(int i = before; i <= after; i++) test2[i] = 1;
    for(int i = 1; i <= (before - from) / 2; i++) {
        test2[before - i] = 1;
    }
    for(int i = 1; i <= (to - after) / 2; i++) {
        test2[after + i] = 1;
    }
}

int connected(int from) {
    //cerr << "connected " << from << endl;
    int to = from;
    while(true) {
        if(test[to+1] == 0 && test[to] == 0) break;
        to++;
    }
    query(from, to - 1);
    return to;
}

void search(int from) {
    if(from > 2*N-1) return;
    if(test[from] == 0) {
        search(from+1);
        return;
    }
    search(connected(from) + 1);
}

int main() {
    //cout.precision(10);
    cin >> N;
    for(int i = 1; i <= 2 * N - 1; i++) cin >> a[i];
    ll ok = 2 * N - 1;
    ll ng = 1;
    while(ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        //cerr << "MID " << mid << endl;
        for(int i = 1; i <= 2*N-1; i++) {
            test2[i] = 0;
            if(a[i] <= mid) test[i] = 1;
            else test[i] = 0;
        }
        bool checker = true;
        for(int i = 1; i <= 2*N-1; i+=2) {
            if(test[i] == 0) checker = false;
        }
        if(checker) {
            ok = mid;
            continue;
        }
        search(1);
        /*
        for(int i = 1; i <= 2*N-1; i++) {
            cout << test[i] << " ";
        }
        cout << endl;
        for(int i = 1; i <= 2*N-1; i++) {
            cout << test2[i] << " ";
        }
        cout << endl;
        */
        if(test2[N] == 1) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}
