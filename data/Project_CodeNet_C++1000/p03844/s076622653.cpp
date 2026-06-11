#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long double ld;

int main(){
    int t=1;
    //cin>>t;
    while(t--){
        int a,b;
        char c;
        cin>>a>>c>>b;
        if(c=='+'){
            cout<<a+b;
        }
        else
            cout<<a-b;
    }
}