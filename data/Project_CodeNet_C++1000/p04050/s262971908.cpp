#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define endl '\n'
using namespace std;
const int N=2e5+100;
ll a[N];
int32_t main(){
    ll n,m;
    cin >> n >> m;
    vector <int> b;
    for (int i=0;i<m;i++){
        cin >> a[i];
        if (a[i]%2==1) b.pb(a[i]);
    }
    if (b.size()>2){
        cout << "Impossible" << endl;
        return 0;
    }
    if (b.size()==2){
        b.pop_back();
        for (int i=0;i<m;i++){
            if (a[i]%2==0) b.pb(a[i]);
        }
        for (int i=n-1;i>-1;i--){
            if (a[i]%2==1){
                b.pb(a[i]);
                break;
            }
        }
        for (int i=0;i<b.size();i++){
            cout << b[i] << " ";
        }
        cout << endl;
        if (b[0]!=1){
            cout << m << endl;
            cout << b[0]-1 << " ";
        }
        else{
            cout << m-1 << endl;
        }
        for (int i=1;i<b.size()-1;i++){
            cout << b[i] << " ";
        }
        cout << b.back()+1 << endl;
        return 0;
    }
        for (int i=0;i<m;i++){
            if (a[i]%2==0) b.pb(a[i]);
        }
        for (int i=0;i<b.size();i++){
            cout << b[i] << " ";
        }
        cout << endl;
        if (b[0]!=1){
            cout << m+1 << endl;
            cout << b[0]-1 << " ";
        }
        else{
            cout << m << endl;
        }
        for (int i=1;i<b.size();i++){
            cout << b[i] << " ";
        }
        cout <<1  << endl;
        return 0;


}
