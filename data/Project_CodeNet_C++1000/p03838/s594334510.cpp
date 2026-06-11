// AGC 009 A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    ll x,y; cin >> x >> y;
    ll ans = abs(abs(x) - abs(y));
    if((x >= 0 && y < 0) || (x < 0 && y > 0)){
        ans+=1;
    }else{
        if(x>y && abs(x) > 0 && abs(y) > 0) ans+=2;
        else if(x > y) ans+=1;
    }
    cout << ans << endl;
    return 0;
}