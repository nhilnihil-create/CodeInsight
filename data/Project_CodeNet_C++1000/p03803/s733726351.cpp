#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())


ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main(){
    int a,b;
    cin >> a >> b;

    if(a==1){
        a = 14;
    }
    if(b==1){
        b = 14;
    }
    
    if(a>b){
        puts("Alice");
    }else if(a==b){
        puts("Draw");
    }else{
        puts("Bob");
    }

    return 0;
}