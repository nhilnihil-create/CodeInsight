#include<bits/stdc++.h>
#define ll long long 
#define P pair<ll ,ll>
using namespace std;

ll gcd(ll a,ll b){
    if(a<b)return gcd(b,a);
    if(a%b==0)return b;
    return gcd(b ,a%b);
}
int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int ans = 2*n;
    for(int i=0;i<n;i++){
        bool end = true;
        for(int j=0;i+j < n;j++){
            if(s[i+j]!=t[j]){
                end = false;
            }
        }
        if(end){
            ans = i+n;
            break;
        }
    }

    cout << ans << endl;
}