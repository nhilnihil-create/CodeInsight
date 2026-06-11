#include <iostream>
#include <climits>
#define ll long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, k;
    int arr[100005]; 
    ll score=INT_MIN, pref[100005], pos[100005], maxi=0;
    cin >> n >> k;
    pref[0]=0;
    pos[0]=0;
    
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        pref[i]=pref[i-1]+arr[i];
        pos[i]=pos[i-1];
        if(arr[i]>0){
            pos[i]+=arr[i];
        }
    }
    for(int l=0; l<=n-k; l++){
        int r=l+k;
        maxi = max(pref[r]-pref[l]+pos[n]-pos[r]+pos[l], pos[n]-pos[r]+pos[l]);
        if(score<maxi){
            score = maxi;
        }
    }
    cout << score << endl;
    return 0;
}