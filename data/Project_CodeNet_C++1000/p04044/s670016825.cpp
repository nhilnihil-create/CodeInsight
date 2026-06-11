#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
typedef long long int ll;
void solve()
{
    int N,L,i;
    cin>>N>>L;
    string S[N];
    for(i=0;i<N;i++) cin>>S[i];
    sort(S,S+N);
    for(i=0;i<N;i++) cout<<S[i];
    return;
}
int main()
{
    solve();
}