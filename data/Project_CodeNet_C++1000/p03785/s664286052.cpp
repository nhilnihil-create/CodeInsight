# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int arr[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,c,k;
    cin>>n>>c>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    int cnt=0,ans=0;
    int patokan = arr[1]+k;
    for(int i=1;i<=n;i++){
        cnt++;
        if(arr[i]>patokan || cnt>c){
            ans++;
            patokan=arr[i]+k;
            cnt=1;
        }

    }
    cout<<ans+1<<endl;
}