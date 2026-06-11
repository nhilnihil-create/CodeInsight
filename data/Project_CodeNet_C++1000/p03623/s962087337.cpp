#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i = 0;i < (n);i++)

int main(){
    int x, a, b;
    cin >> x >> a >> b;
    string ans;
    int disa = abs(x-a);
    int disb = abs(x-b);
    if(disa < disb) ans = "A";
    else ans = "B";
    cout << ans << endl;
}