#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,k;
    cin >> t;
    k=t;
    vector <long long> side;
    long long n;
    while(k--)
    {
        cin >> n;
        side.push_back(n);
    }
    sort(side.begin(),side.end(),greater<long long>());
    long long a=0,b=0,i;
    for(i=0;i<t-1;i++)
    {
        if(side[i]==side[i+1])
        {
            if(a==0) a=side[i];
            else b=side[i];
            i++;
        }
        if(a>0 && b>0) break;
    }
    cout << a*b << endl;
}