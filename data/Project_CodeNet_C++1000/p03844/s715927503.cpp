#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
long long a,b;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin>>a>>s>>b;
    if (s=="+") cout<<a+b<<endl;
    else cout<<a-b<<endl;
    return 0;
}