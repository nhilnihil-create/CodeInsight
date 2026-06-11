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
    int ar[3];
    for(int i=0;i<3;i++){cin>>ar[i];}
    sort(ar,ar+3);
    if(ar[0]==5 && ar[1]==5 && ar[2]==7){cout<<"YES\n";}
    else{cout<<"NO\n";}
}


