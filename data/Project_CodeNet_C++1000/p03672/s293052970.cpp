#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main (){
    string s;
    cin >> s;
    int c = 0;
    for(int i = 1; i < s.size() / 2;i++){
        if(s.substr(0 , i) == s.substr(i , i)){
            c = 2 * i;
        }
    }
    cout << c << endl;
}