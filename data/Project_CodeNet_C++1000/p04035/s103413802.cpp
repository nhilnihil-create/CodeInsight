#include <bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define s second
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
using namespace std;

int arr[100005];

int main(){
    faster
    int T = 1;
    while(T--){
        int n,l;
        cin>>n>>l;
        
        rep(i,0,n-1) {
            cin>>arr[i];
        }
        
        int ind;
        
        int f = 0;
        rep(i,0,n-2){
            if(arr[i]+arr[i+1] >= l){
                f = 1;
                ind = i;
                break;
            }
        }
        
        
        if(!f){
            cout<<"Impossible";
        } else{
            cout<<"Possible\n";
            for(int i=0; i<ind; i++){
                cout<<i+1<<" ";
            }
            for(int i=n-2; i>ind; i--){
                cout<<i+1<<" ";
            }
            cout<<ind+1;
        }
        
        
    }
    return 0;
}






