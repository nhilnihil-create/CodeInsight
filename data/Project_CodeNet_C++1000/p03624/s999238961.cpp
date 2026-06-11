#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define ll long long
#define coYes cout << "Yes" << endl
#define coYES cout << "YES" << endl
#define coyes cout << "yes" << endl
#define coNo cout << "No" << endl
#define coNO cout << "NO" << endl
#define cono cout << "no" << endl
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
int gcd(int a, int b){ //最大公約数
    if(a%b == 0){
        return b;
    }else{
    return gcd(b, a%b);
    }
}
ll lcm(ll a, ll b) { //最小公倍数
    return a * b / gcd(a, b);
  }

ll digit_sum(ll a){ //10進桁和
    ll ans=0;
    while(a>0){
      ans+=a%10;
      a/=10;
    }
    return ans;
  }

int main(){
  string s;
  cin >> s;
  string a = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++) {
      for (int j = 0, l = s.length(); j < l; j++) {
        if (s[j] == a[i]) {
            break;
        }
        if (j == l - 1 && s[j] != a[i]) {
            cout << a[i] << endl;
            return 0;
        }
      }
  }
    cout << "None" << endl;
    return 0;
}