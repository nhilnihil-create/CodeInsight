#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l,i,k;
    string s[100];
    scanf("%d%d",&n,&l);
    for(i=0; i<n; i++)
        cin >> s[i];
    sort(s,s+n);
    for(i=0; i<n; i++)
        cout << s[i];
    return 0;
}
