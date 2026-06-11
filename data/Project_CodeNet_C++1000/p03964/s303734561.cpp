#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n],t[n];
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> a[i];
    }
    ll pt=t[0];
    ll pa=a[0];
    for(int i = 1; i < n; i++) {
        double pr=double(pt)/double(pa);
        ll nt=t[i];
        ll na=a[i];
        double nr=double(nt)/double(na);
        if(pr>1){
            if(nr>pr){
                pa=((pa+na-1)/na)*na;
                pt=pa/na*nt;
            }
            else{
                pt=((pt+nt-1)/nt)*nt;
                pa=pt/nt*na;
            }
        }
        else{
            if(nr<pr){
                pt=((pt+nt-1)/nt)*nt;
                pa=pt/nt*na;
            }
            else{
                pa=((pa+na-1)/na)*na;
                pt=pa/na*nt;
            }
        }
    }
    cout << pt+pa << "\n";

    return 0;
}