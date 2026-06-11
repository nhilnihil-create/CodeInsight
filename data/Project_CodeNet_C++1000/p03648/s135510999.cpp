#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

lint ans[55];

int main(){
    lint K; cin >> K;

    for(int i=0;i<50;i++) ans[i] = i + K / 50;

    K %= 50;
    for(int i=0;i<K;i++){
        ans[i] += 50;
        for(int j=0;j<50;j++) if(i != j) ans[j]--;
    }

    cout << 50 << endl;
    for(int i=0;i<50;i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}