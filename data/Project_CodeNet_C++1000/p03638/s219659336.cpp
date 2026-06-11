#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
#define RAP(i, n) for(ll i=0;i<(n);i++)
#define FOR(i, a, b) for(ll i=(a);i<(b);i++)

int main(){
    ll h, w, n, count=1;
    bool flag = false;
    cin >> h >> w >> n;
    ll a[n];
    RAP(i, n){
        cin >> a[i];
    }
    ll c[h][w];
    RAP(i, h){
        if(i%2){
            RAP(j, w){
                RAP(k, a[count-1]){
                    c[i][j]=count;
                    j++;
                    if(j==w ){
                        if(k<a[count-1]-1){
                            a[count-1] -= k+1;
                            flag = true;
                        }
                        break;
                    }
                }
                j--;
                if(!flag){
                    count++;
                }else{
                 	flag = false; 
                }
            }
        }else{
            for(ll j=w-1;j>=0;j--){
                RAP(k, a[count-1]){
                    c[i][j]=count;
                    j--;
                    if(j==-1 ){
                        if(k<a[count-1]-1){
                            a[count-1] -= k+1;
                            flag = true;
                        }
                        break;
                    }
                }
                j++;
                if(!flag){
                    count++;
                }else{
                 	flag = false; 
                }
            }
        }
        
    }
    RAP(i, h){
        RAP(j, w){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
