//E.H//
# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n,arr[100005];
int byk[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int maxi=-1;
    int mini=1000000000;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        byk[arr[i]]++;
        maxi=max(maxi,arr[i]);
        mini=min(mini,arr[i]);
    } 
    if(maxi==mini){
        if(maxi==n-1 || 2*maxi<=n){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    else if(maxi==mini+1){
        int x=byk[mini];
        int y=byk[maxi];
        if(x+1<=maxi && maxi<=x+(y/2)) {
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    else cout<<"No"<<endl;
}