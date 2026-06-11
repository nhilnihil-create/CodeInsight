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
    char w[110];
    int s[26]={0};
    cin>>w;
    for(int i=0;w[i]!='\0';i++){
        s[w[i]-'a']++;
    }
    rep(i,26){
        if(s[i]%2!=0){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}