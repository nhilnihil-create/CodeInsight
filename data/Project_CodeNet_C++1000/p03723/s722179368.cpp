#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a,b,c,count=0;
    cin>>a>>b>>c;
    if((a==b && b==c) || (a%2 == 1 || b%2 == 1 || c%2 == 1)) {
        if(a%2 == 0 && b%2 == 0 && c%2 == 0) {
            cout<<-1<<"\n";
            return 0;
        }
        else {
            cout<<0<<"\n";
            return 0;
        }
    }
    while(a%2 == 0 && b%2 == 0 && c%2 == 0) {
        ll d=a, e=b, f=c;
        a = (e+f)/2;
        b = (d+f)/2;
        c = (d+e)/2;
        count++;
    }
    cout<<count<<"\n";
}