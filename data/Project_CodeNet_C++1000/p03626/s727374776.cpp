#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define ll long long
int main(void){
    ll n;
    ll inf = 1000000007;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    ll ans = 3;
    if(n==1) ans = 3;
    else if(n==2) ans = 6;
    else if(n>=3){
        ll check;
        if(s1[0]==s2[0])
            check = 0;
        else if(s1[0]!=s2[0]){
            check = 1;
            ans = 6;
        }
        for(ll i = check; i < n-1; i++){
            if(s1[i+1]==s2[i+1]){
                if(s1[i]==s2[i])
                    ans = (ans*2)%inf;
            }
            else if(s1[i+1]!=s2[i+1]){
                if(s1[i]!=s2[i])
                    ans = (ans*3)%inf;
                else if(s1[i]==s2[i])
                    ans = (ans*2)%inf;
                i++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}