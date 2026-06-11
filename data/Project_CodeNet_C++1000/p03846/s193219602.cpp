#include <bits/stdc++.h>
using namespace std;


#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define mp make_pair
const int mod = 1e9+7;
void solve(){
     int n;
     cin >> n;
     map<int,int> h;
     for(int i = 0 ; i < n ; i++){
        int temp;cin>>temp;
        h[temp]++;
     }
     ll ans = 1;
     if(n%2){

        for(int i = n-1 ; i > 0; i -=2 ){
           if(h[i] == 2)ans =(2*ans)%mod;
           else ans = 0;
        }
        if(h[0] == 1)cout<<ans<<"\n";
        else cout<<"0\n";
     }
     else {
        for(int i = n-1; i >= 1; i-=2){
           if(h[i] == 2)ans=(2*ans)%mod;
           else ans = 0;
        }
        cout<<ans<<"\n";
     }


}


int main(){
   solve();
}