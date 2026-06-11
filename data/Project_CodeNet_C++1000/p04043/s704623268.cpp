#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);

       int t=1;
       //cin>>t;
       while(t--)
       {
               int a[3];
               cin>>a[0]>>a[1]>>a[2];
               sort(a,a+3);
               if(a[0]==5 && a[1]==5 && a[2]==7)
                    cout<<"YES";
               else
                    cout<<"NO";
       }
}
