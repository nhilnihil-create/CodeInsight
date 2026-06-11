#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N+1);
    int b = 1, ans = 0;
    for(int i = 0; i < N; ++i) cin >> a[i+1];
    for(int i = 1; i < N+1; ++i){
        ++ans;
        b = a[b];
        if(b == 2) break;
        else if(i == N) ans = -1;
    }
    cout << ans << endl;
    return 0;
}