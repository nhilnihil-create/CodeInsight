#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int m=s.size(); int l=t.size();
    string s_ref="";
    string t_ref="";
    int d=0;

    for(int i=0; i<min(m,l); i++){
        s_ref = s[m-1-i] + s_ref;
        t_ref = t_ref + t[i];
        if(s_ref==t_ref) d=s_ref.size();
    }
    cout << m+l-d << endl;
}