#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
long long int x,y;
cin>>x>>y;
if(x==1&&y==1){
    cout<<"Draw";
    return 0;
}
 else if(x==1){
    cout<<"Alice";
    return 0;}
    else if(y==1){
    cout<<"Bob";
    return 0;}


if(x>y)
    cout<<"Alice";
else if(x<y)
    cout<<"Bob";
else
    cout<<"Draw";


    return 0;
}
