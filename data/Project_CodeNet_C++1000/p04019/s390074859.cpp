#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    string s;
    cin >> s;
    int n=0,w=0,S=0,e=0;
    bool hantei=true;
    rep(i,s.size()){
        if(s[i] == 'N') n =1;
        else if(s[i] == 'W') w = 1;
        else if(s[i] == 'S') S =1;
        else if(s[i] == 'E') e = 1;
    }
    if(n != S) hantei =false;
    if(w != e) hantei =false;

    if(hantei) cout << "Yes"<<endl;
    else    cout << "No" <<endl;
}
    
