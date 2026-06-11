#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

typedef long long ll;
string s;
ll ans=0;

ll calc(string t){
    int n=t.size(), i=0;
    ll sum=0;
    while(i < n){
        ll tmp=0;
        while(t[i] != '+' && i < n){
            if(t[i] == '#'){
                i++;
                tmp *= 10; 
                continue;
            }
            tmp += t[i++]-'0';
        }
        sum += tmp;
        i++;
    }
    return sum;
}

int main(){
    cin >> s;
    int n=s.size();
    for(int bit=0; bit<(1<<n-1); bit++){
        string tmp = s;
        rep(i, n-1){
            if(bit&(1<<i)) tmp.insert(i*2+1, "+");
            else tmp.insert(i*2+1, "#");
        }
        ans += calc(tmp);
    }
    cout << ans << endl;
}