#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const int INF = INT_MAX / 2;

int main(){
    int N; cin >> N;
    string s, t; cin >> s >> t;
    for (int i = 0; i < N; i++)
    {
        if(s.substr(i, N-i) == t.substr(0, N-i)){
            s += t.substr(N-i, i);
            break;
        }
        if(i==N-1) s += t;
    }
    cout << s.size() << endl;
}