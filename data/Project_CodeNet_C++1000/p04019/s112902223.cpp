#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int N,W,E,S;
    N = E = W = S = -1;

    for(int i=0; i<(int)s.size(); i++){
        if(s[i] == 'N') N = i;
        else if(s[i] == 'S') S = i;
        else if(s[i] == 'E') E = i;
        else if(s[i] == 'W') W = i;
    }

    string ans = "Yes";

    if((N != -1 && S == -1) || (N == -1 && S != -1)) ans = "No";
    if((W != -1 && E == -1) || (W == -1 && E != -1)) ans = "No";

    cout<<ans<<endl;

    return 0;
}