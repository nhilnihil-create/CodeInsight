#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[100001];
    int i;
    cin>>s;
    for(i=0;i<strlen(s);i++){
        if(i%2==0) cout<<s[i];
    }
    return 0;
}
