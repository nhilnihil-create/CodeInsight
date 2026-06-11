#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    int guuki = 100;
    for(int i = 0; i < N; i++) {
        int s;
        cin >> s;
        cnt+=s;
        if(s%2 == 1) {
            guuki = min(guuki,s);
        }
    }
    if(cnt%10 != 0) {
        cout << cnt << endl;
    }
    else if(guuki != 100) {
        cout << cnt-guuki << endl;
    }
    else {
        cout << 0 << endl;
    }
}