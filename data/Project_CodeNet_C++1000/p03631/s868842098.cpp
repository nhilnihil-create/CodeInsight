/*
   Author : tarang
*/
#include<bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with(false); cin.tie(0);cout.tie(0);
const int MOD = 1000000007;
#define PI = acos(-1)
using namespace std ;
int a[106];
int main(){
    string s ; cin >> s ;
    string t = s ;
    reverse(t.begin() , t.end());
    if(t==s)
    cout << "Yes";
    else cout << "No";
}

