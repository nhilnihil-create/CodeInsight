#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    vector<string> s(3);
    cin>>s[0]>>s[1]>>s[2];
    int t = 0;
    vector<int> i(3);
    while(1){
        if(s[t].size() == i[t]){
            cout << char('A' + t) << endl;
            break;
        }
        t = s[t][i[t]++]-'a';
    }
}