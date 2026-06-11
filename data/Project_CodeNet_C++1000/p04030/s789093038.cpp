#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    string s,t;
    cin>>s;
    int n=s.size();
    rep(i,n){
        if(s[i]=='0') t+='0';
        else if(s[i]=='1') t+='1';
        else if(t.size()!=0) t.pop_back();
    }
    cout<<t;
}