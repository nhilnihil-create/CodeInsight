#include<bits/stdc++.h>
using namespace std;
int main(void)
{ 
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int c = 0;int bth = 0;
    for(int  i = 0;i<n;i++)
    {
         if(s[i]=='c')
            {
               cout<<"No"<<endl;
            }
          else
            { 
                if(s[i]=='b')
                 bth++;
                if((s[i]=='a' && c<(a+b)) || (s[i]=='b' && c<(a+b) && bth<=b)){
                  cout<<"Yes"<<endl;  
                  c++;
                }
                else
                  cout<<"No"<<endl;
            }
    }
}
