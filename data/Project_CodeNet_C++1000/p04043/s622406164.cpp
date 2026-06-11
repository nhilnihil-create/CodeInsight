#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    int five=0,seven=0;
    for(int i=0;i<3;i++)
    {
        if(a[i]==5)
        {
            five++;
        }
        else if(a[i]==7)
        {
            seven++;
        }
    }
    if(five==2 && seven==1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}





