#include <bits/stdc++.h> //JuniorMonster a.k.a Sho10
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define all(a) (a).begin(), (a).end()
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sz size
#define f first
#define s second
#define pb push_back
#define er erase
#define in insert
#define mp make_pair
#define pi pair
#define rc(s) return cout<<s,0
#define mod 1000000007
#define PI 3.14159265359
#define CODE_START  ios_base::sync_with_stdio();cin.tie();cout.tie();
using namespace std;
ll n;
string s;
int32_t main(){
CODE_START;
cin >> s;
n=s.size();
if(s[0]==s[n-1]){
    if(n%2==0){
        rc("First");
    }else {
    rc("Second");
    }
}
if(n%2==0){
    rc("Second");
}else rc("First");
return 0;}
