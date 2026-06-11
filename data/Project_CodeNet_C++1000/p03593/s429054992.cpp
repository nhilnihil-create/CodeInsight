#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main(){
    int h, w, n = 26;
    string ans = "No";
    cin >> h >> w;
    int A[26] = {0};
    for(int i = 0; i < h*w; i++) {
        char c;
        cin >> c;
        A[c-'a']++;
    }
    int f = 0;
    if(h%2 == 1)f++;
    if(w%2 == 1)f++;
    if(f == 0){
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(A[i]%4 != 0) flag = false;
        }
        if(flag) ans = "Yes";
    }
    else if(f == 1){
        int two = 0;
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(A[i]%2 != 0) {
                flag = false;
                break;
            }
            if(A[i] % 4 != 0 && A[i] % 2 == 0) two++;
        }
        int x;
        if(h % 2 == 1) x = w;
        else x = h;
        if(two * 2 > x) flag = false;
        if(flag) ans = "Yes";
    }
    else{
        int one = 0, two = 0, four = 0;
        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(A[i] % 2 == 1) one++;
            if(A[i] % 4 != 0 && A[i] % 2 == 0) two++;
        }
        if(one != 1 || two * 2 > h + w - 1) flag = false;
        if(flag) ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}
