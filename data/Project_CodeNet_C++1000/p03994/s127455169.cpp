#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   string s;cin >>s;
   ll k;cin >>k;
   ll n=s.size();
   vector<ll>num(n);
//   vector<bool>ch(n,true);
    for (int i = 0; i < n; ++i) {
        num[i]=(('a'-s[i])+26)%26;
    }
//    for (int i = 0; i < n; ++i) {
//        cout <<num[i]<<" ";
//    }
    for (int i = 0; i < n; ++i) {
        if (num[i] <= k) {
            k -=num[i];
            s[i]='a';
        }
        if(i==n-1){
            k%=26;
            s.back()+=k;
        }
    }
    cout <<s<<endl;
    return 0;
}