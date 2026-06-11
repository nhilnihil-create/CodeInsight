#include <bits/stdc++.h>
using namespace std;

int n , i ,u;

vector<int> v  , f ;

int delta(int a,int b,int c)
{
    int d ,x1,x2;

    d = b*b - 4*a*c ;

    x1 = (-1*b - sqrt(d))/(2*a);
    x2 = (-1*b + sqrt(d))/(2*a);

    if(x1 > 0)
        return x1 ;
    return x2 ;
}

int N,M,K,a[100003];

pair <int,vector<int> > p[100004];

int main()
{
    ios_base :: sync_with_stdio(false) ;
    u = 2;
    for(i=0; ; i++)
    {
        if(u > 4472)
            break;
        v.push_back(u*(u+1)/2);
        u++;
    }
    cin >> n ;
    if(binary_search(v.begin() , v.end() , n))
    {
        int ans = delta(1,1,-2*n);
        for(i=1; i<=ans; i++)
            cout << i << endl ;
    }
    else
    {
        int index = upper_bound(v.begin(),v.end(),n) - v.begin() , sum = 0 ;
        for(i=0; i<=index; i++)
            f.push_back(i+1);
        for(i=0; i<f.size(); i++)
            sum += f[i] ;
        sum = n - sum ;
        for(i=f.size()-1 ; i > -1 && sum; i--)
        {
            sum--;
            f[i]++;
        }
        for(i=0; i<f.size(); i++)
            cout << f[i] << endl ;
    }
    return 0;
}
