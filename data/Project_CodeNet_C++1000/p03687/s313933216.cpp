#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

bool judge(string s, char c){
    int n = s.length();
    bool ans = true;
    rep(i,n){
        if(s[i] != c){
            ans = false;
            break;
        }
    }
    return ans;
} //　文字列sが全てcか判定する

int main(){
    string s; cin >> s;

    int ans = 100;
    for(char c = 'a'; c <= 'z'; (char)c++){
        int count = 0;
        string data = s;
        while(!judge(data,c)){
            count++;
          	string next = "";
            int num = data.length();
            rep(i,num-1) {
              if(data[i] == c || data[i+1] == c) next += c;
        	  else next += data[i];
            }
          	data = next;
        }
        ans = min(ans, count);
    }

    cout << ans << endl;
}

