#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  optimize   ios::sync_with_stdio(0); cin.tie(0);
#define PI  acos(-1.0)
#define RESET(a, b) memset(a, b, sizeof(a))
#define pb push_back
int main()
{
     optimize
     int n;
     cin>>n;
     ll a[n+2];
     set<ll>st;
     map<ll,ll>Map;
     for(int i=0;i<n;i++){
        cin>>a[i];
        Map[a[i]]++;
        st.insert(a[i]);
     }
     ll x=0,y=0;
     for(auto it=st.rbegin();it!=st.rend();++it){
          if(Map[*it]>=2){
            x=*it;
            break;
          }
     }
     for(auto it=st.rbegin();it!=st.rend();++it){
        if(*it!=x && Map[*it]>=2){
            y=*it;
            break;
        }
     }
     if(Map[x]>=4) cout<<x*x<<endl;
     else cout<<x*y<<endl;
}
