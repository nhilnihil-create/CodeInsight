#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    string str;
    cin>>str;
    int l=0;
    while(l<str.size() && str[l]!='A')
    l++;
    int r=str.size()-1;
    while(r>=0 && str[r]!='Z')
    r--;
    cout<<r-l+1<<endl;
}