#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0;
    int l = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == ')' && r == l) cnt++;
        else if(s[i] == '(') l++;
        else if(s[i] == ')') r++;
        //cout << s << endl;
    }
    for(int i = 0; i < cnt; i++) s = "("+s;
    int k = l-r;
    //cout << k << endl;
    for(int i = 0; i < k; i++) s = s+")";
    cout << s << endl;
    return 0;
}