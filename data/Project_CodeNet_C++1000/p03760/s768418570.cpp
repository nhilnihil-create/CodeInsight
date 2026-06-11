#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string o,e;
    int oi=0,ei=0;
    cin>>o>>e;

    for(long int i=0;i<max(o.length(),e.length());i++){
        if(i<o.length())cout<<o[i];

        if(i<e.length())cout<<e[i];
    }


    return 0;
}
