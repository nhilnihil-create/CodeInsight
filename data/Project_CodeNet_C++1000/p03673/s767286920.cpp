#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    deque<int> dq;
    bool rev=false;
    for(int i=0;i<n;i++){
        if(rev){
            dq.push_front(a[i]);
            rev=false;
        }else{
            dq.push_back(a[i]);
            rev=true;
        }
    }
    if(rev){
        for(int i=n-1;i>=0;i--){
            cout << dq[i] << " ";
        }
        cout << endl;
        return 0;
    }else{
        for(int i=0;i<n;i++){
            cout << dq[i] << " ";
        }
        cout << endl;
        return 0;
    }
}