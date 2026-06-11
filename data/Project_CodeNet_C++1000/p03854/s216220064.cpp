#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;

int main() {
    string str;
    cin >> str;
    queue<string> que;
    string tmp[4] = {"dream", "dreamer", "erase", "eraser" };

    rep(i,4) que.push(tmp[i]);

    while(!que.empty()){
        string s;
        s = que.front();
        que.pop();
        rep(i,4){
            string tmp_s = s + tmp[i];
            if(tmp_s.size() < str.size() && str.substr(0,tmp_s.size()) == tmp_s){
                que.push(tmp_s);
            }
            else if(tmp_s.size() == str.size() && str == tmp_s){
                cout << "YES" << endl;
                return 0;
            }
        } 
    }
    cout << "NO" << endl;

}