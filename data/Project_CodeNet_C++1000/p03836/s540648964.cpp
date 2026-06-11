#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll gcd(ll x ,ll y){
    ll r = x%y;
    if(r==0)return y;
    else return gcd(y ,r);
}

int main(){
    int sx ,sy ,tx ,ty;
    cin >> sx >> sy >> tx >> ty ;
    int x = tx - sx;
    int y = ty - sy;
    for(int i=0;i<y;i++) cout << 'U';
    for(int i=0;i<x;i++) cout << 'R';
    for(int i=0;i<y;i++) cout << 'D';
    for(int i=0;i<x;i++) cout << 'L';
    cout << 'L' ;
    for(int i=0;i<=y;i++) cout << 'U';
    for(int i=0;i<=x;i++) cout << 'R';
    cout << "DR";
    for(int i=0;i<=y;i++) cout << 'D';
    for(int i=0;i<=x;i++) cout << 'L';
    cout << 'U'<<endl;
}