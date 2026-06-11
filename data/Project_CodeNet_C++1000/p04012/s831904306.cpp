#include<bits/stdc++.h>
#define pi acos(-1)
#define mx 1500000
#define mod 1000000007
#define pii pair<int,int>
typedef long long ll;
using namespace std;
void fastio()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main()
{
    fastio();
    int i,j,t,n,k,l,x,y;
    //cin>>t;
    //while(t--){
     string w;
     cin>>w;
     int v[28]={0};
     //cout<<w<<endl;
     for(i=0;i<w.size();i++){
        k=w[i]-97;
        v[k]++;
         }
      for(i=0;i<28;i++){
        if(v[i]%2==1){
            cout<<"No"<<endl;
            return 0;
        }
      }
     cout<<"Yes"<<endl;
     //}
 return 0;
}
