#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll for (int i =0 ;i<n ;i++)
#define ll2 for (int j =0 ;j<k ;j++)
#define wh while (k>0)
#define pb push_back
#define stack stack<int>
//#define vector vector<int>vec(n)
#define set set<int>
#define sort sort(vec.begin(),vec.end())
#define  popcount __builtin_popcount
#define beg begin()
#define endi end()
#define f first
#define sec second
#define iso ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main()
{
    int a ,b ;
    cin>> a>>b ;
    if(a+b>=24)
    {
        cout<< (a+b)%24<<endl  ;
    }
    else
    {
        cout<< a+b<<endl ;
    }
}
