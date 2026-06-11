#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string s; cin >> s;
    string t = "CODEFESTIVAL2016";
    int c = 0;
    for(int i = 0; i < 16; i++){
        if(s[i] != t[i])c++;
    }
    cout << c  << endl;

    return 0;
}