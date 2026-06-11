#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,s;
    cin >> k >> s;
    int c=0;
    for(int i=0;i<=k;i++)
        for(int j=0;j<=k;j++)
            if(s-(i+j)<=k && s-(i+j)>-1)
                c++;
    cout << c;
    return 0;
}