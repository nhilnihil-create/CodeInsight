#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //good luck kittu!
    string s; cin>>s;
    int n = s.size();
    for(int i = 0; i<n-1; i++) if(s[i]==s[i+1]) return cout<<i+1<<" "<<i+2<<"\n", 0;
    for(int i = 0; i<n-2; i++) if(s[i]==s[i+2]) return cout<<i+1<<" "<<i+3<<"\n", 0;
    cout<<"-1 -1\n";
    return 0;
}