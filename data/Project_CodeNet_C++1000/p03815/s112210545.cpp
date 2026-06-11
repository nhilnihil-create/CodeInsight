#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
long long x;
cin>>x;
if(x==6){
    cout<<1;
    return 0;
}
long long res;
if(x%11==0){
    res=0;
}
else{
    if(x%11>6){
        res=2;
    }
    else{
        res=1;
    }
}
cout<<(x/11*2)+res;



    return 0;
}
