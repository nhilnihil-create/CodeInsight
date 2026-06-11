#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976
const double PI = 3.1415926535897932;

int a[1000005];
string s; 
int n;

bool check(){
    bool res = true;
    

    if(a[n-1] == 1){
        if(!((s[n-1] == 'o' && a[n-2] == a[0]) || (s[n-1] == 'x' && a[n-2] != a[0]))){
            res = false;   
        }
    }else{
        if(!((s[n-1] == 'x' && a[n-2] == a[0]) || (s[n-1] == 'o' && a[n-2] != a[0]))){
            res = false;   
        }
    }
    if(a[0] == 1){
        if(!((s[0] == 'o' && a[n-1] == a[1]) || (s[0] == 'x' && a[n-1] != a[1]))){
            res = false;   
        }
    }else{
        if(!((s[0] == 'X' && a[n-1] == a[1]) || (s[0] == 'o' && a[n-1] != a[1]))){
            res = false;   
        }
    }
    return res;
}

void p(){
    rep(i,n){
        if(a[i] == 1) cout << 'S';
        else cout << 'W';
    }
    cout << endl;
}

void make(){
    for(int i = 2; i < n; i++){
        if(a[i-1] == 1){
            if(s[i-1] == 'o') a[i] = a[i-2];
            else a[i] = (-1*a[i-2]);
        }else{
            if(s[i-1] == 'o') a[i] = (-1*a[i-2]);
            else a[i] = a[i-2];
        }
    }
}

int main()
{
    cin >> n; cin >> s;
    
    a[0] = 1; a[1] = 1;
    make();
    if(check()){
        p();
        return 0;
    }

    a[0] = 1; a[1] = -1;
    make();
    if(check()){
        p();
        return 0;
    }

    a[0] = -1; a[1] = 1;
    make();
    if(check()){
        p();
        return 0;
    }

    a[0] = -1; a[1] = -1;
    make();
    if(check()){
        p();
        return 0;
    }
    cout << -1 << endl;
}