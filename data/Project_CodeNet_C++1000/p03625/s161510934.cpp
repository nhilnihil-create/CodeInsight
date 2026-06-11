//Bismillahir Rahmanir Rahim
//In the name of Allah the Most Merciful
//Astagfirullahil laji Rabbi Minkulli Jamio
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
int i,j,k;
main()
{

 int n;cin>>n;
 int a[n]={0};
 int b[n]={0};int j=0;
 for(i=0;i<n;i++)
    cin>>a[i];
    int c[n]={0};k=0;
    map<int,int> m;
    for(i=0;i<n;i++)
    {
        m[a[i]]++;
        if(m[a[i]]==2)
        {
            b[j++]=a[i];
        }
        if(m[a[i]]==4)
        {
            c[k++]=a[i];
        }
    }
//for(i=0;i<j;i++) cout<<b[i]<<' ';
//for(i=0;i<k;i++) cout<<c[i]<<' ';
   sort(b,b+j);
   sort(c,c+k);
   if(k==0&&j==0) cout<<0<<endl;
   else
   if(k==0) cout<<b[j-1]*b[j-2]<<endl;
   else if(j<=1) cout<<c[k-1]*c[k-1]<<endl;
   else cout<<max(c[k-1]*c[k-1],b[j-1]*b[j-2]);
}
