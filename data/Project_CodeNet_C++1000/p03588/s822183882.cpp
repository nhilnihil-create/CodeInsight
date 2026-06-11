#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        p.at(i) = make_pair(a,b);
    }
    sort(p.begin(),p.end());
    reverse(p.begin(), p.end());
    int answer = p.at(0).first + p.at(0).second;
    cout << answer;
}