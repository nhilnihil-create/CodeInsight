#include<iostream>
using namespace std;
int a[26];
int main()
{
    string s;cin>>s;
    for(char c:s) a[c-'a']++;
    for(auto x:a) if(x>1) return puts("no")*0;
    puts("yes");
}
    