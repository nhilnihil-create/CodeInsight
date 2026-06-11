#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int a,b,c;
cin>>a>>b>>c;
if(a==5&&b==5&&c==7){
    cout<<"YES";
}
else if(a==5&&b==7&&c==5){
    cout<<"YES";
}
else if(a==7&&b==5&&c==5){
    cout<<"YES";
}
else
    cout<<"NO";



    return 0;
}
