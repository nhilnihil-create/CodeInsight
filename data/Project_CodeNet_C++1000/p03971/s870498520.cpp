#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b, count=0, bcount=0; string s; cin >> n >> a >> b >> s;
    for(int i=0;i<n;i++){
        //cout << a << ':' << b << ':' << count << ':' << bcount << endl;
        if(s[i] == 'a' && count < a+b) {cout << "Yes" << endl; count++;}
        else if(s[i] == 'b' && count < a+b && bcount < b) {cout << "Yes" << endl; bcount++; count++;}
        else cout << "No" << endl;
    }
    return 0;
}

