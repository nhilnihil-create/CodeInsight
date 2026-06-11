#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >>n;
    vector<ll> a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll sub = a.back()-a[0];
    if(a.back()-a[0]>1){
        cout <<"No"<<endl;
        return 0;
    }else if(sub==1){
        i=0;
        ll coler = 0;
        while(a[i]<a.back()){
            coler++;
            i++;
        }
        ll nokori=1+a[0]-coler;
        if(nokori<1){
            cout << "No"<< endl;
            return 0;
        }
        if(n-i>=nokori*2){
            cout << "Yes"<<endl;
        }else{
            cout << "No"<<endl;
        }
    }else{
        if(a[0]+1==n){
            cout << "Yes"<<endl;
        }else{
            if(a[0]*2<=n){
                cout << "Yes"<<endl;
            }else{
                cout << "No"<<endl;
            }
        }
    }
    return 0;
}