#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int x,a,b;
    cin>>x>>a>>b;
    if(abs(a-x)>abs(b-x)) cout<<'B';
    else cout<<'A';
}