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
    int n;
    cin >> n;
    pair<int,int> usagi[n];

    rep(i,n){
        int a;  cin >> a;
        a--;
        usagi[i] = make_pair(i,a);
    }

    int ans(0);
    rep(i,n){
        int t = usagi[i].second;
        if(usagi[t].second == i){
            ans++;
            usagi[t].second = -1;
        }
    }

    cout << ans << endl;

    return 0;
}