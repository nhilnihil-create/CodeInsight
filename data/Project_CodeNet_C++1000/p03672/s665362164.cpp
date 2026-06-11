#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    string s;
    cin >> s;
    int n = s.length();

    --n;
    if(n&1)
        --n;

    for(int i=n; i>=0; --i){
        string a = s.substr(0, i/2);
        string b = s.substr(i/2, a.length());

        if(a==b){
            cout << a.length()*2;
            return 0;
        }
    }
}
