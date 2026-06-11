#include <bits/stdc++.h>
using namespace std;
using ll = long long; // ll は long long　と同じとする。(int64_t)
int main(){
    int N;
    cin >> N;
    int ans = 0;
    int a[N + 1];
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= N; i++){
            if(a[a[i]] == i){
                ans++;
            }
    }
    cout << ans / 2 << endl;
}
