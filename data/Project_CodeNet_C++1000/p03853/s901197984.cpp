#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int h,w;
    cin >> h >> w;
    char C[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> C[i][j];
        }
    }
    for(int i=0;i<2*h;i++){
        for(int j=0;j<w;j++){
            cout << C[i/2][j];
        }
        cout << endl;
    }
}