#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ar[3];
    cin>>ar[0]>>ar[1]>>ar[2];
    sort(ar,ar+3);
    if(ar[0]+ar[1]==ar[2])
        cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
}
