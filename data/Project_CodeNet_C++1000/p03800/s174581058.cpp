#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 100005;
bool res[maxn];
int n;
string str;

bool check() {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        int l = ((i-1)+n)%n;
        int r = (i+1)%n;
        //cout << " i = " << i << " l = " << l << " r = " << r << '\n';
        if (res[i]) {
            //cout << " left: " << res[l] << " right: " << res[r] << '\n';
            //cout << str[i] << '\n';
            if (str[i] == 'x' && res[l] == res[r]) flag = true;
            if (str[i] == 'o' && res[l] != res[r]) flag = true;
        }
        if (!res[i]) {
            if (str[i] == 'x' && res[l] != res[r]) flag = true;
            if (str[i] == 'o' && res[l] == res[r]) flag = true;
        }
        //if (flag) cout << " bad at " << i << '\n';
    }
    return !flag;
}

void attempt() {
    for (int i = 1; i < n; i++) {
        int l = ((i-1)+n)%n;
        int r = (i+1)%n;
        if (res[i]) {
            //cout << i << " is sheep\n";
            if (str[i] == 'o') res[r] = res[l];
            if (str[i] == 'x') res[r] = !res[l];
            //cout << "set right to " << res[r] << '\n';
        } else {
            if (str[i] == 'o') res[r] = !res[l];
            if (str[i] == 'x') res[r] = res[l];
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        if (res[i]) cout << "S";
        else cout << "W";
    }
    cout << '\n';
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> str;

    res[0] = true;
    res[1] = true;
    attempt();
    if (check()) print();

    res[0] = true;
    res[1] = false;
    attempt();
    if (check()) print();

    res[0] = false;
    res[1] = false;
    attempt();
    if (check()) print();

    res[0] = false;
    res[1] = true;
    attempt();
    if (check()) print();

    cout << "-1\n";
}
/*

 */