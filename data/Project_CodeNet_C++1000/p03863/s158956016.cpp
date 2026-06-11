#include<bits/stdc++.h>
using namespace std;
string s;

int main()
{
    cin>>s;
    int len=s.size();
    if((s[0]==s[len-1] && len%2==0) || (s[0]!=s[len-1] && len%2==1))  printf("First\n");
    else  printf("Second\n");
    return 0;
}
