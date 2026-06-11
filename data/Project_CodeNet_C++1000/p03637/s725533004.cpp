#include <bits/stdc++.h>
using namespace std;
using vl = vector<long long>;
using ll = long long;

int main(){
    int n; cin >> n;
    int n2=0,n4=0,nodd=0,n1=0;
    bool can = true;
    for(int ix=0;ix<n;ix++){
        ll a; cin >> a;
        if(a%4==0) n4++;
        else if(a%2==0) n2++;
        //else if(a==1) n1++;
        else nodd++;
    }
    if(n4+1<nodd) can = false;
    else if(n4+1-nodd<(n2%2)) can = false;
    
    cout << (can ? "Yes" : "No") << endl;
}