#include <bits/stdc++.h>

using namespace std;

#define int long long
long long pw[15], sum, cur = 0, pw1[15];

signed main() {
    cin.tie(0), ios::sync_with_stdio(0);
    pw[0] = 1;
    for(int i = 1; i <= 9; i++){
        pw[i] = pw[i - 1] * 10;
    }
    int num = -1;
    for(int i = 9; i >= 0; i--){
        cout << "? " << pw[i] << "\n";
        cout.flush();
        char c;
        cin >> c;
        if(c == 'Y'){
            num = i + 1;
            break;
        }
    }
    if(num == 10){
        for(int i = 9; i >= 0; i--){
            if(i == 0){
                cout << "! " << pw[i] << "\n";
                cout.flush();
                exit(0);
            }
            cout << "? " << pw[i] - 1 << "\n";
            cout.flush();
            char c;
            cin >> c;
            if(c == 'N'){
                cout << "! " << pw[i] << "\n";
                cout.flush();
                exit(0);
            }
        }
    }
    for(int i = 1; i <= num; i++){
        int l = 0, r = 9, mid;
        if(i == 1)
            l = 1;
        if(i < num){
            while(l < r){
                mid = (l + r + 1) >> 1;
                sum = cur * 10 + mid;
                cout << "? " << sum << "\n";
                cout.flush();
                char c;
                cin >> c;
                if(c == 'Y')
                    l = mid;
                else
                    r = mid - 1;
            }
            cur = cur * 10 + l;
        }
        else{
            for(int j = l; j <= r; j++){
                int sum = cur * 10 + j;
                if(i == num)
                sum = sum * 10 + 9;
                cout << "? " << sum << "\n";
                cout.flush();
                char c;
                cin >> c;
                if(c == 'Y'){
                    cur = cur * 10 + j;
                    break;
                }
            }
        }
    }
    cout << "! " << cur << "\n";
    cout.flush();
    exit(0);
}