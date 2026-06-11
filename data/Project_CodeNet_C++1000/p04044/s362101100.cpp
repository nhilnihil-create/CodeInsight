#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
typedef long long int lli;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define JUGAD freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
using namespace std;

int main(){
    FAST;
    int n,l;cin>>n>>l;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n);
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
}


