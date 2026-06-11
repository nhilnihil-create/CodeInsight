#include <bits/stdc++.h>

using namespace std;

const int MAX_N=50+10;
long long int a[MAX_N];

int main()
{
    //INPUT
    long long int k;
    cin >> k;
    //SOLVE
    long long int y=(k+50-1)/50+50,x=(y-50+1)*50;
    for(int i=0;i<50;i++)
    {
        a[i]=y;
    }
    for(long long int i=x;i>k;i--)
    {
        sort(a,a+50);
        a[49]-=50;
        for(int j=0;j<49;j++)
        {
            a[j]++;
        }
    }
    //OUTPUT
    cout << 50 << endl;
    for(int i=0;i<50;i++)
    {
        cout << a[i] << " ";
    }
}
