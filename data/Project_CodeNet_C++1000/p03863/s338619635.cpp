#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    bool flag1, flag2;
    if (s.size() % 2 == 0) {
        flag1 = true;
    } else {
        flag1 = false;
    }

    if (s[0] == s[s.size()-1]) {
        flag2 = true;
    } else {
        flag2 = false;
    }

    if (flag1 ^ flag2) {
        cout << "Second\n";
    } else {
        cout << "First\n";
    }
}