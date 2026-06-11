#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    string s;   cin >> s;
    int ans=s.size(), tc=0, sc=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='S') sc += 1;
        else if(0<sc && s[i]=='T'){
            tc += 1;
            int x = min(sc, tc);
            ans -= 2*x;
            sc -=x; tc -= x;
        }
    }
    
    //if(s.back()=='T') ans -= min(sc, tc)*2;
    cout << ans << endl;
}

