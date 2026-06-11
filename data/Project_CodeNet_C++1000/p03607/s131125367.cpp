//Written by:Poushi
//Dept_CSE of IUT
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define fixedprecision(n) cout<<fixed<<setprecision(n)
#define frf(i,a,n) for(i=a;i<n;i++)
#define frb(i,b,n) for(i=b;i>n;i--)

int main()
{
    int n,t,i,j;
    set<int> st;
    set<int>::iterator it;
    cin>>t;
    while(t--)
    {
       cin>>n;
       it=st.find(n);
       if(it==st.end())
       {
           st.insert(n);
       }
       else
        st.erase(it);
    }
    cout<<st.size()<<endl;
}
