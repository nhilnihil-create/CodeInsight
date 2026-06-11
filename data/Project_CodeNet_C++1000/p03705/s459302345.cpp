#include<bits/stdc++.h>

#define faster     ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define read       freopen("input.txt", "r", stdin);
#define write      freopen("output.txt", "w", stdout);
#define endd        '\n'
#define ll         long long
#define sq(a)      ((a) * (a))

using namespace std;
int main()
{
      faster;
      double pi = 2 * acos(0.0);
      ll int n,i,t,j,k,m=0,a=0,b=0,c=0,d=0,p=0,q,r,x=250,y=10,z,count=0;
      cin>>n>>a>>b;
      if(a==b)cout<<"1"<<endl;
      else if(b<a || n==1)cout<<"0"<<endl;
      else{
            p=(b-a)*(n-2);
            cout<<p+1<<endl;
      }
      return 0;
}
//Sheikh Tafsir Rahman
//CSE IUT