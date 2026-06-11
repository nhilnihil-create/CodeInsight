#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;

int main(){
    cin >> n;
    cin >> s;
    ll count=0;
    ll left=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='(') count++;
        else if(s[i]==')'&&count==0) left++;
        else if(s[i]==')'&&count>0) count--;
    }
    string res="";
    for(ll i=0;i<left;i++) res+="(";
    res+=s;
    for(ll i=0;i<count;i++) res+=")";
    cout << res << endl;
    return 0;
}
