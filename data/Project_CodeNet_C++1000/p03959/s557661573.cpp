#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007LL;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
int main(){
    int n;
    cin >> n;
    long long t[n],a[n];
    rep(i,n){
        cin >> t[i];
    }
    rep(i,n){
        cin >> a[i];
    }
    bool flt[n],fla[n];
    flt[0] = true;
    fla[n-1] = true;
    for(int i = 1;i<n;i++){
        if(t[i-1]==t[i]) flt[i] = false;
        else flt[i] = true;
    }
    for(int i = n-2;i>=0;i--){
        if(a[i]==a[i+1]) fla[i] = false;
        else fla[i] = true;
    }
    long long ans = 1;
    for(int i = 0;i<n;i++){
        if(flt[i]){
            if(t[i]>a[i]){
                cout << 0 << endl;
                return 0;
            }
        }
        else{
            if(fla[i]){
                if(t[i]<a[i]){
                    cout << 0 << endl;
                    return 0;
                }
            }
            else{
                ans*=min(a[i],t[i]);
                ans%=MOD;
            }
        }
    }
    cout << ans << endl;
}