#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 2e5+5;
ll int arr[sz]={0},arr1[sz]={0};
//ll int arr[100][100]= {0};
int prime[10005]= {0};
vector <ll int> vec,vec1,vec2;
//vector <pair <int,int>> vec;
set<ll int>st;

int main()
{
    ll int a,b,x;
    cin>>a>>b>>x;

    ll int k = b/x;
    ll int l = a/x;
    k++, l++;
    if(a%x==0)
        l--;

    cout<<k-l<<endl;

}
