#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define full(a) a.begin(),a.end()
#define stoink stack<ll>
#define vec vector <ll>
#define vg vector<vector<ll> >
#define vgw vector<vector<pair<ll,ll> >
#define pa pair<ll,ll>
#define mp make_pair
#define pb push_back
int main() {
    ll n,l;
    cin >> n >> l;
    vec arr(n);
    ll i;
    for( i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool flag = false;
    for( i = 0; i < n-1 ; i++ ) {
        if( arr[i] + arr[i + 1] >= l) {
            flag = true;
            cout << "Possible" << endl;
            for(ll j = 0 ; j < i ; j++)
                cout<< j + 1 <<endl;
            for(ll j = n - 1 ; j > i + 1; j--)
                cout<< j <<endl;
            cout << i +1 <<endl;
            break;
            }
        }

    if(!flag)
        cout<<"Impossible";
    return 0;
}
