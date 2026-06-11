#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll s,c;
    cin >> s >> c;
    if(s >= c){
        cout << c / 2 << endl;
        return 0;
    }
    else
    {
        ll sum = s;
        c -= s * 2;
        sum += c / 4;
        cout << sum << endl;
    }
    
}