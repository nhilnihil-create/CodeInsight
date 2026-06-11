#include<bits/stdc++.h>
using namespace std;

int count( int n )
{
    int ans =0;
    while( n%2==0)
    {
        ans++;
        n = n/2;
    }
    return ans;
}
int main()
{
    int n ;
    cin>>n;
    int ans = INT_MIN;
    int val =0;
    for(int i=1;i<=n;i++)
    {
        int temp =  count(i);
        if( temp > ans )
        {
            val = i;
            ans =  temp;
        }
    }
    cout<<val;
}