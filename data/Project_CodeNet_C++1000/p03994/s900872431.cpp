#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(){
    ll k;
    string str;
    cin >> str >> k;
    rep(i, str.size()){
        if(str[i] == 'a') continue;
        int d = 'z' - str[i];
        if(d < k){
            str[i] = 'a';
            k -= d+1;
        }
    }
    k = k % ('z' - 'a' + 1);
    int rest = (k + str.back() - 'a') % ('z' - 'a' + 1);
    str[str.size()-1] = (char)(rest + 'a');
    cout << str << "\n";
}