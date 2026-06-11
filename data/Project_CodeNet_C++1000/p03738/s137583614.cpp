#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string a, b;
    cin >> a >> b;
    if(a.size() > b.size()){
        b = string(a.size() - b.size(), '0') + b;
    }
    else{
        a = string(b.size() - a.size(), '0') + a;
    }

    if(a > b) puts("GREATER");
    else if(a < b) puts("LESS");
    else puts("EQUAL");
}