#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int main(){
    string s;
    cin >> s;
    int n(0),w(0),ss(0),e(0);

    for(ll i=0; i<s.length(); i++){
        if(s[i]=='N') n++;
        if(s[i]=='W') w++;
        if(s[i]=='S') ss++;
        if(s[i]=='E') e++;
    }

    bool x(false),y(false);

    if(n==ss) y=true;

    if((n>=1)&&(ss>=1)) y=true;

    if(w==e) x=true;

    if((w>=1)&&(e>=1)) x=true;

    if(x&&y){
        cout <<"Yes"<<endl;
    } 
    else{
        cout <<"No"<<endl;
    }
    return 0;
}