#include <bits/stdc++.h>
using namespace std;

int main () {

    long long a,b,c;
    cin>>a>>b>>c;

    long long r= b/c - a/c;
    if(a%c==0){
        r++;
    }
    cout<<r;
}
