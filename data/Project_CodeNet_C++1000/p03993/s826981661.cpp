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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        int x;
        cin >> x;
        x--;
        a[i]=x;
    }
    int ans=0;
    rep(i,n){
        if(a[a[i]]==i && a[i]>i) ans++;
    }
    cout << ans << endl;
}