#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    for(int i = 0;i < n;i++)cin >> l.at(i) >> r.at(i);
    int ans = 0;
    for(int i = 0;i < n;i++)ans += (r.at(i) - l.at(i) + 1);
    cout << ans << endl;
}