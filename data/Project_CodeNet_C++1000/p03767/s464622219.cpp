#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[1000000];
    long long ans = 0;
    for(int i = 0; i < 3*N; i++){
        cin >> a[i];
    }

    sort(a,a + 3*N, greater<int>());

    for(int i = 0; i < N ; i++){
        ans += a[1 + 2*i];
    }
    cout << ans << endl;
    return 0;
}