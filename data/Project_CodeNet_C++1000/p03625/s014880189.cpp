#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

int main(void) {
    int N;cin>>N;
    map<ll, ll> mp;
    for (int i = 0; i < N; i++) {
        ll A;cin>>A;
        if (mp.find(A) != mp.end()) mp[A] += 1;
        else mp[A] = 1;
    }
    priority_queue<ll> que;
    for (map<ll, ll>::iterator it = mp.begin(); it != mp.end(); ++it) {
        ll num = it->second;
        while (num >= 2) {
            que.push(it->first);
            num /= 2;
        }
    }
    if (que.size() < 2) cout << 0 << endl;
    else {
        ll a = que.top();
        que.pop();
        ll b = que.top();
        cout << a * b << endl;
    }
    return 0;
}