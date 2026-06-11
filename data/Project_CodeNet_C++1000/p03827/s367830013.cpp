#include<bits/stdc++.h>
using namespace std;
#define mod 997
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,x,n) for(int i=x;i<n;i++)

int main() {
    int n;
    string s;
    cin>>n>>s;
    int x=0;
    int max=x;
    for(int i=0;i<n;i++){
        if(s[i]=='I')x++;
        else x--;
        if(max<x)max=x;
    }
    cout<<max;
}