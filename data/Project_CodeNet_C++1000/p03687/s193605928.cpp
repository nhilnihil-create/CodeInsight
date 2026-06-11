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
    string s;
    cin>>s;
    int n=s.size(),mini=10000;
    for(auto c='a';c<='z';c++){
        int cnt=0,maxi=0;
        rep(i,n){
            if(s[i]==c){
                maxi=max(maxi,cnt);
                cnt=0;
            }
            else cnt++;
        }
        maxi=max(maxi,cnt);
        mini=min(mini,maxi);
    }
    cout<<mini;
}