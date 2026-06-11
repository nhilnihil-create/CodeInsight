#define MOD 1000000007;
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll long long

#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
set<int> st[N+1];
int main() {

    int x;
    cin>>x;
    int i=0;
    ll y=0;
   while(y+i<x)
       y+=i,i++;
   cout<<i;

}