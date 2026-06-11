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
    char s[100010];
    cin>>s;
    bool a[26];
    rep(i,26) a[i]=false;
    for(int i=0;s[i]!='\0';i++){
        a[s[i]-'a']=true;
    }
    rep(i,26){
        if(!a[i]){
            cout<<(char)(i+'a');
            return 0;
        }
    }
    cout<<"None";
}