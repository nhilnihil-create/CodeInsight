#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,l;
     cin>>n>>l;
     long long int a[n];
     for(int i=0;i<n;i++)
          cin >>a[i];
     long long int i,k=n-1;
     for(i=0;i<n-1;i++)
     {
          if(a[i]+a[i+1]>=l)
                {
                    k=i;
                    break;
                }
     }
     if(k==n-1)
          cout<<"Impossible"<<endl;
     else
     {
      cout << "Possible" << endl;
     for(int j=0;j<k;j++)
        cout <<j+1<<" ";
     for(int j=n-2;j>i;j--)
        cout <<j+1<<" ";
     cout<<i+1<<endl;
     }
}
