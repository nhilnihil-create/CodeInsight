#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
    string A,B;
    cin>>A>>B;
    ll lenA = A.size(),lenB = B.size();
    if(lenA>lenB)puts("GREATER");
    else if(lenA<lenB)puts("LESS");
    else
    {
        for(int i=0; i<lenA; i++)
        {
            if(A[i]>B[i])
            {
                puts("GREATER");
                return 0;
            }
            else if(A[i]<B[i])
            {
                puts("LESS");
                return 0;
            }
        }
        puts("EQUAL");
    }
    return 0;
}
