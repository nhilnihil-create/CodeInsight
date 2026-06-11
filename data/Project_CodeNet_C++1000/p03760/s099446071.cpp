///بِسْمِ الّٰلهِ الرَّحْمٰنِ الرَحِيْمِ
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
int main()
{
     ios_base::sync_with_stdio(false);cin.tie(NULL);
    int i,n,t,j=0,p,x,a=0,b,l=0,r=0,y,k,c,sum=0,m,d;
     string s1,s2;
     cin>>s1>>s2;k=0;j=0;
     for(i=0;i<s1.size()+s2.size();i++){
         if(k<s1.size()){cout<<s1[k++];}
         if(j<s2.size()){
            cout<<s2[j++];i++;
         }
     }
     return EXIT_SUCCESS;
}
