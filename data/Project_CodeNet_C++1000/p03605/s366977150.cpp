#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if(n% 10 == 9 ||n/10 == 9)
        cout <<"Yes\n";
    else
        cout <<"No\n";
}