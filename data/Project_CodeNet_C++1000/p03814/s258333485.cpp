#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string s;
    cin >> s;
    int a = INF;
    int z = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == 'A'){
            if(a > i) a = i;
        }
        else if(s[i] == 'Z'){
            if(z < i) z = i;
        }
    }
    cout << z - a + 1 << endl;

    return 0;
}