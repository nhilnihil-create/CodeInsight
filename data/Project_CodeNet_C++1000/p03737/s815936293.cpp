#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
    string str;
    getline(cin,str);

    stringstream  ss(str);
    string word;
    while(ss>>word)
    {
        transform(word.begin(),word.end(),word.begin(),::toupper);
        cout<<word[0];
    }
}