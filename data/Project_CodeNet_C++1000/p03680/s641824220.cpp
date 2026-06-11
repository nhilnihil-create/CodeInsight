#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> a(N+1);
    for(int i=1; i<=N; i++) cin >> a.at(i);

    vector<bool> used(N+1, false);

    int cnt = 0;
    int pos = 1;
    used.at(pos) = true;
    bool flg = false;
    while(true){
        pos = a.at(pos);
        cnt++;
        if(used.at(pos) == true) break;
//        cout << pos << endl;
        used.at(pos) = true;

        if(pos == 2){
            flg = true;
            break;
        }
    }

    if(flg) cout << cnt << endl;
    else cout << -1 << endl;
    return 0;
}