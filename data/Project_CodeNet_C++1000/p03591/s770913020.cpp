#include<iostream>
#include<vector>
#include<map>
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

    string S;
    cin >> S;
    if (S.substr(0, 4) == "YAKI") cout << "Yes\n";
    else cout << "No\n";
}