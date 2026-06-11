#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
void Main(){
    int whi,hhi,n,wlo=0,hlo=0;
    cin>>whi>>hhi>>n;
    For(i,0,n){
        int x,y,a;
        cin>>x>>y>>a;
        if(a==2){
            whi=min(whi,x);
        }
        else if(a==1){
            wlo=max(wlo,x);
        }
        else if(a==4){
            hhi=min(hhi,y);
        }
        else if(a==3){
            hlo=max(hlo,y);
        }
    }
    cout<<max(whi-wlo,0)*max(hhi-hlo,0)<<endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}