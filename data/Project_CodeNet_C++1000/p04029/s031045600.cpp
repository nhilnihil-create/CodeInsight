#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N; cin >> N;
    int sum = 0;
    for(int i  =1; i <= N; ++i) sum+=i;
    cout << sum << endl;
}

int main(){
    solve();
    return 0;
}