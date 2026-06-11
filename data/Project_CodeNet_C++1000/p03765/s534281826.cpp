#include <bits/stdc++.h>
typedef  int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
/// khodaya komak kon
/// ya navid navid
const int N=2e5;
ll t0[N];
ll t1[N];
ll t10[N];
ll t11[N];
int32_t main(){
    string s;
    cin >> s;
    for (int i=1;i<=s.size();i++){
        t0[i]=t0[i-1];
        t1[i]=t1[i-1];
        if (s[i-1]=='A'){
            t0[i]++;
        }
        else{
            t1[i]++;
        }
    }
    string u;
    cin >> u;
    for (int i=1;i<=u.size();i++){
        t10[i]=t10[i-1];
        t11[i]=t11[i-1];
        if (u[i-1]=='A'){
            t10[i]++;
        }
        else{
            t11[i]++;
        }
    }
    ll q;
    cin >> q;
    for (int i=0;i<q;i++){
        ll x,y;
        cin >> x >> y;
        ll w,h;
        cin >> w >> h;
        ll z=t0[y]-t0[x-1];
        z-=t1[y]-t1[x-1];
        z+=3e8;
        z%=3;
        ll z1=t10[h]-t10[w-1];
        z1-=t11[h]-t11[w-1];
        z1+=3e8;
        z1%=3;
        //cout << z << " " << z1 << endl;
        if (z1!=z){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        cout << '\n';
    }
}












