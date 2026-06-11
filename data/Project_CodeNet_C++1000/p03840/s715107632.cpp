#include <bits/stdc++.h>
#define ll long long
#define INF INT_MAX 
#define mod 1000000007
using namespace std;
int main(){
    ll i,o,t,j,l,s,z;
    cin >> i >> o >> t >> j >> l >> s >> z;
    ll ans = 0;
    ans += o;
    if(i%2==1&&j%2==1&&l%2==1){
        ans+=3;
        i--; j--; l--;
        ans += (i/2)*2 + (j/2)*2 + (l/2)*2;
    }else if(i%2==0&&j%2==0&&l%2==0){
        ans += (i/2)*2 + (j/2)*2 + (l/2)*2;
    }else if((i+j+l)%2==1){
        ans += (i/2)*2 + (j/2)*2 + (l/2)*2;
    }else{
        if(i>0&&l>0&&j>0){
            ans += 3;
            i--; j--; l--;
            ans += (i/2)*2 + (j/2)*2 + (l/2)*2;
        }else{
            ans += (i/2)*2 + (j/2)*2 + (l/2)*2;
        }
    }
    cout << ans << endl;
}