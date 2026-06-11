using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define divup(a,b) ( ( (a) + ( (b) - 1u) ) / (b) ) // a/b の余り切り上げ
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
ll mod = 1000000007;

signed main(){
    string s;
    ll k,ss;
    cin>>s>>k;
    ss = s.size();
    rep(i,ss){
        if(k<=0) break;
        else{
            if((s[i]!='a')&&('z'-s[i]+1)<=k){
                k -= 'z' - s[i] +1;
                s[i] = 'a';
            }
        }
    }
    k %= 26;
    rep(i,ss){
        if(k<=0) break;
        else{
            if(('z'-s[ss-1-i])<=k){
                k -= 'z' - s[ss-1-i];
                s[ss-1-i] = 'z';
            }else{
                s[ss-1-i] += k;
                k = 0;
            }
        }
    }
    cout<<s<<endl;
}
