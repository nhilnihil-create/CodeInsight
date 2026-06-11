#include <bits/stdc++.h>
using namespace std;
#include <string>

int a, c;
string b, d="-", e="+";

int main () {
    cin>>a>>b>>c;
    if (b [0]==d [0]) {cout<<a-c<<endl;}
    else if (b [0]==e [0]) {cout<<a+c<<endl;}
}