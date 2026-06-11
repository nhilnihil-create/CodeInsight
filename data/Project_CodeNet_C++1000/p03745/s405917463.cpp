# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n,arr[100005];
int cnt;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    // 0=turun 1=naik
    int tren=2;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i==1) continue;
        if(arr[i]>arr[i-1] && tren==0){
            tren=2;
            cnt++;
        }
        else if(arr[i]<arr[i-1] && tren==1){
            tren=2;
            cnt++;
        }
        else if(tren==2){
            if(arr[i]>arr[i-1]) tren =1;
            else if(arr[i]<arr[i-1]) tren =0;
        }
    }
    
    cout<<cnt+1<<endl;
}