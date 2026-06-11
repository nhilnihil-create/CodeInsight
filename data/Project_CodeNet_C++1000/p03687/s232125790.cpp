#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
string s;

int calc(char c){
    int ret = 0;
    string t = s;
    while(count(t.begin(), t.end(), t[0]) != t.size()){
        ret++;
        string new_t;
        for(int i = 0 ; i + 1 < (int)t.size() ; i++){
            if(t[i] == c || t[i + 1] == c) new_t += c;
            else new_t += t[i];
        }
        t = new_t;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    int ans = 1e9;
    for(char c = 'a' ; c <= 'z' ; c++){
        ans = min(ans, calc(c));
    }
    cout << ans << endl;
}
