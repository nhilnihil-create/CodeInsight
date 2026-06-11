#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin >> s;
    ll n=s.size();
    ll ans=1000,mx,t;
    ll i,j;
    for(i=0;i<n;i++){
        j=0;
        mx=0;
        t=0;
        while(j<n){
            if(s[i]!=s[j])t++;else {mx=max(t,mx);t=0;}
            j++;
        }
        mx=max(t,mx);
        ans=min(mx,ans);
    }
    cout << ans;
    return 0;
}
