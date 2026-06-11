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
    int n=s.size();
    for(int i=2;i<=n;i+=2){
        int cnt=0;
        for(int j=0;j<(n-i)/2;j++){
            if(s[j]==s[j+(n-i)/2]) cnt++;
        }
        if(cnt==(n-i)/2){
            cout<<n-i;
            return 0;
        }
    }
}