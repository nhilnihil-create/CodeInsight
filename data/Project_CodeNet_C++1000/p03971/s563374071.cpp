#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
     ll n=0,a=0,b=0;
     cin>>n>>a>>b;
     string s;
     cin>>s;
     ll pass=0;
     ll overseas=0;
     for(int i=0;i<n;i++){
         if(s[i]=='a')
         {
            if(pass<a+b)
            {
                cout<<"Yes"<<"\n";
                pass++;
                
            }
            else
            cout<<"No"<<"\n";
         }
         else if(s[i]=='b'){
             if(pass<a+b && overseas<b){
                 cout<<"Yes"<<"\n";
                 pass++;
                 overseas++;
             }
             else
             {cout<<"No"<<"\n";
                 overseas++;}
         }
         else
         cout<<"No"<<"\n";
     }
        
    }

    return 0;
}
