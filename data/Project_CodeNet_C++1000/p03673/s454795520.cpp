#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    vector<ll> l(0);
    vector<ll> r(0);
    for (int i=0; i<n; i++){
        ll a; cin>>a;
        if(i%2==0) r.push_back(a);
        else l.push_back(a);
    }
    if(n%2==0){
        reverse(l.begin(), l.end());
        for(int i=0; i<n/2; i++) cout << l[i] << ' ';
        for(int i=0; i<n/2; i++){
            if(i==n/2-1) cout << r[i];
            else cout << r[i] << ' ';
        }
    }
    else{
        reverse(r.begin(), r.end());
        for(int i=0; i<n/2+1; i++) cout << r[i] << ' ';
        for(int i=0; i<n/2; i++){
            if(i==n/2-1) cout << l[i];
            else cout << l[i] << ' ';
        }
    }
    cout << endl;
}