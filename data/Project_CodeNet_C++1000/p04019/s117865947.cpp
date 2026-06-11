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
    map<char,int> dir;
    dir['N'];
    dir['W'];
    dir['S'];
    dir['E'];

    string s;   cin >> s;

    rep(i,s.length()){
        dir[s[i]]++;
    }

    bool x(false),y(false);
    if(dir['W']==dir['E'])
        x = true;
    if(dir['W']>=1&&dir['E']>=1){
        x = true;
    }

    if(dir['S']==dir['N']){
        y = true;
    }
    if(dir['S']>=1&&dir['N']>=1){
        y = true;
    }

    if(x&&y){
        puts("Yes");
    }else{
        puts("No");
    }

    return 0;
}