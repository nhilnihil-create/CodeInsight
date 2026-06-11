#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long
#define vi vector<int>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

string S;

void solve(){
    if(S.substr(0,4) == "YAKI")
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main(){
    cin >> S;

    solve();
}
