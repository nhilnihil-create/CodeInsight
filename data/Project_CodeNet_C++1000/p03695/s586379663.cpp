#include <iostream>
#include <cstring>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    int a[8]; memset(a, 0, sizeof(a));
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        int x; cin >> x;
        if(x < 400) {
            a[0]++;
        }
        else if(x < 800) {
            a[1]++;
        }
        else if(x < 1200) {
            a[2]++;
        }
        else if(x < 1600) {
            a[3]++;
        }
        else if(x < 2000) {
            a[4]++;
        }
        else if(x < 2400) {
            //cout << a[5] << endl;
            a[5]++;
            //cout << a[5] << endl;
        }
        else if(x < 2800) {
            a[6]++;
        }
        else if(x < 3200) {
            a[7]++;
        }
        else{
             cnt++;
        }
    }

    int nnum = 0;
    for(int i = 0; i < 8; ++i){
        if(a[i] == 0) continue;
        nnum++;
    }
    if(nnum == 0) cout << 1 << " " << cnt << endl;
    else cout << nnum << " " << nnum + cnt << endl;
    return 0;
}
//Sawt the editorial