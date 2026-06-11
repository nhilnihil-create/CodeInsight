#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    string s;
    cin>>s;
    int n=s.length();
    int x=n;
    x-=2;
    cout<<s[0]<<x<<s[n-1];
}