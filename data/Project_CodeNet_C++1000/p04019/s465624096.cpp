#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    
    bool N = false;
    bool W = false;
    bool S = false;
    bool E = false;
    rep(i,n){
        if(s[i] == 'N')N = true;
        if(s[i] == 'W')W = true;
        if(s[i] == 'S')S = true;
        if(s[i] == 'E')E = true;
    }
    
    if(N != S || W != E)cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}