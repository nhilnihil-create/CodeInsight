#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    string s, t;
    cin >> N >> s >> t;
    string S = s + t;
    int len = (int)S.size();
    int anc = len / 2 - 1;
    int anc_n = anc + 1;
    int cnt = 0;
    int ans = 0;
    for(int i = anc, j = anc_n; i >= 0; i--, j++){
        cnt++;
        string a = S.substr(i, cnt);
        string b = S.substr(anc_n, cnt);
        if(a == b) ans = cnt;
    }    
    cout << len - ans << endl;
    return 0;
}