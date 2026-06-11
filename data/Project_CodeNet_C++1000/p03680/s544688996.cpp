#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        int b;
        cin >> b;
        b--;
        a.at(i) = b;
    }
    int nwbt = 0;
    int cnt = 0;
    while(true){
        if(nwbt == 1){
            cout << cnt << endl;
            break;
        }
        if(cnt >= N){
            cout << -1 << endl;
            break;
        }
        nwbt = a.at(nwbt);
        cnt++;
    }
}