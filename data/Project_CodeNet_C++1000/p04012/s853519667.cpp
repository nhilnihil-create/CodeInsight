#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;cin>>a;
    map<char,int> m;
    for(auto i:a)m[i]++;
    for(char i='a';i<='z';i++){if(m[i]%2){cout<<"No\n";return 0;}}
    cout<<"Yes\n";
}
