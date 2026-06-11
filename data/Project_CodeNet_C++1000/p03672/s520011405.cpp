#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long int
#define MOD 1e9+7
#define start int t;cin>>t;while(t--)
#define debug(x) cout<<"#"<<x<<"\n"
#define en "\n"
#define vi vector<int>
#define vli vector<long long int>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define print_all(x) for(auto t:x) cout<<t<<" "; cout<<en
#define F first
#define S second
using namespace std;

vector<ll> printDivisors(ll n) 
{ 
    vector<ll> v;
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                v.pb(i);
  
            else {
                v.pb(i);
                v.pb(n/i);
            } 
        }
    }
    return v;
} 

bool isEven(string s){
    int len=s.size();
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[i+len/2]){
            return false;
        }
    }
    return true;
}
void solve(){
   string s;
   cin>>s;
   int len=s.size();
   int dec=2;
   int ans;
   while(s.size()>=2){
       s=s.substr(0,len-dec);
       if(isEven(s)){
           ans=s.size();
           break;
       }
       dec+=2;
   }
   cout<<ans;
}


int main(){
    fast;
    //start{
        solve();
    //}
    return 0;

}

