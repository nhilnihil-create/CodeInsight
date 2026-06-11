#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;
typedef long long ll;
int main(){
   #ifndef ONLINE_JUDGE 
      FILE_READ_IN 
      FILE_READ_OUT 
   #endif
    int n,l; cin>>n>>l;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        v.push_back(s);
    }
   sort(v.begin(),v.end());
   for(auto x:v)
    cout<<x;
    cout<<"\n";
   return 0;
}