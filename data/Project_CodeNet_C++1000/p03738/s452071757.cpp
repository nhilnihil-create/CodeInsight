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
    string a,b;
    cin>>a>>b;
    if(a.size()>b.size()) cout<<"GREATER";
    else if(a.size()<b.size()) cout<<"LESS";
    else{
        int n=a.size();
        rep(i,n){
            if(a[i]>b[i]){
                cout<<"GREATER";
                return 0;
            }else if(a[i]<b[i]){
                cout<<"LESS";
                return 0;
            }
        }
        cout<<"EQUAL";
    }
}