#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++) {
        int a;cin >> a;
        if(s.count(a)) s.erase(a);
        else s.insert(a);
    }
    cout << s.size() << endl;

    return 0;
}