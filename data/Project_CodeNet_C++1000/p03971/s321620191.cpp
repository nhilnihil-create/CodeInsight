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
    int n,a,b;
    cin>>n>>a>>b;
    vector<char> s(n);
    rep(i,n) cin>>s[i];
    rep(i,n){
        if(s[i]=='a'){
            if(0<a+b){
                cout<<"Yes";
                a--;
            }else cout<<"No";
        }else if(s[i]=='b'){
            if(0<a+b&&0<b){
                cout<<"Yes";
                b--;
            }else cout<<"No";
        }else cout<<"No";
        cout<<endl;
    }
}