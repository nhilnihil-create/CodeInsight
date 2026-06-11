#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

static const int MAX = 1e6;
static const int NIL = -1;
static const ll INF = 1<<21;
static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
    return arg1.first > arg2.first;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    int a, b;
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        if(a==1) p.at(b-1)++;
        else if(b==1) p.at(a-1)++;
        else {
            p.at(a-1)++;
            p.at(b-1)++;
        }
    }

    for(int i=1;i<n;i++) {
        if(p.at(i)%2==1) { 
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
