#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int d[256];
int main (){
    string s;
    cin >> s;
    for(auto i : s){
        d[i]++;
    }
    for(auto i : d){
        if(i & 1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}