#include <iostream> 
#define ll long long 
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int check=0;
    ll n, sum = 0, k=0;
    int stones[100005], diff[100005];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> stones[i];
        sum+=stones[i];
    }
    for(int i=1; i<=n; i++){
        if(i==n){
            diff[n]=(stones[1]-stones[n]);
        }
        else{
            diff[i]=(stones[i+1]-stones[i]);
        }
    }
    
    if(sum%(n*(n+1)/2)!=0){
        cout << "NO" << endl;
    }
    else{
        k=sum/(n*(n+1)/2);
        for(int i=1; i<=n; i++){
            ll x = ((k-diff[i])/n);
            if(x>=0 && (k-diff[i])%n==0){
                check++;
            }
        }
        if(check==n){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}