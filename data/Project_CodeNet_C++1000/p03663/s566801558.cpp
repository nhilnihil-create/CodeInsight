#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=998244353;
const ll INF=1000000010;
const ll LINF=1000000000000000010;
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,1,-1,0,1,-1,0};
int main(){
    ll s=1;
    int keta=0;
    char c;
    bool f=false;
    for(int i=1;i<=11;i++){
        cout<<"? "<<s<<endl;
        cin>>c;
        keta=i-1;
        if(c=='N'){
            f=true;
            break;
        }
        s*=10;
    }
    if(!f){
        s=1;
        for(int i=1;i<10;i++){
            cout<<"? "<<s+1<<endl;
            cin>>c;
            if(c=='Y'){
                cout<<"! "<<s<<endl;
                return 0;
            }
            s*=10;
        }
    }
    int now=1;
    s=0;
    while(1){
        if(now==keta){
            int en=0;
            if(keta==1){
                en=1;
            }
            for(int i=9;i>=en;i--){
                cout<<"? "<<(s+i)*10<<endl;
                cin>>c;
                if(c=='N'){
                    cout<<"! "<<s+i+1<<endl;
                    return 0;
                }   
            }
            cout<<"! "<<s+en<<endl;
            return 0;
        }else{
            int ok=0,ng=10;
            while(ng-ok>1){
                int mid=(ng+ok)/2;
                cout<<"? "<<s+mid<<endl;
                cin>>c;
                if(c=='Y'){
                    ok=mid;
                }else{
                    ng=mid;
                }
            }
            s+=ok;            
        }
        now++;
        s*=10;
    }
}
