#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=100009;
 
// Happy Coding!


void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    
    string str;
    cin>>str;
    
    int jp=0,ov=0;
    for(int i=0;i<n;i++){
        if(str[i]=='c'){
            cout<<"No\n";
        }
        else{
            if(str[i]=='a'){
                if(jp+ov<a+b){
                    cout<<"Yes\n";
                    jp++;
                }
                else{
                    cout<<"No\n";
                }
            }
            else{
                if(jp+ov<a+b && ov<b){
                    cout<<"Yes\n";
                    ov++;
                }
                else{
                    cout<<"No\n";
                }
            }
        }
    }
}
 
int main() {
    faster;
    int t=1;
    // cin>>t;
    
    while(t-->0){
        solve();
    }
	return 0;
}