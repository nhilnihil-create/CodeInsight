//E.H//
# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
ll n,arr[100005],ps[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){
        ps[i]=ps[i-1] + arr[i];
    }
    for(int i=n-1;i>=1;i--){
        if(ps[i]*2>=arr[i+1]){
            continue;

        }
        else {
            cout<<n-i<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
}