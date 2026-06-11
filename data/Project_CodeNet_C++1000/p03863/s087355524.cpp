#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    ll n=s.size();
    bool flag=true;
    if(s[0]==s[n-1]){
        if((n-3)%2==0) flag=false;
    }
    else{
        if((n-2)%2==0) flag=false;
    }
    if(flag) cout << "First" << endl;
    else cout << "Second" << endl;
}
