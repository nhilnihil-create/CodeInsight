#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

int main(){
    
    string ans;
    cout<<"? 49999999999"<<endl;
    char a;cin>>a;
    if(a=='Y'){
        for(int i=1;i<=4;i++){
            cout<<"? "<<i<<"9999999999"<<endl;
            cin>>a;
            if(a=='Y'){
                ans+='0'+i;
                break;
            }
        }
    }else{
        for(int i=5;i<=9;i++){
            cout<<"? "<<i<<"9999999999"<<endl;
            cin>>a;
            if(a=='Y'){
                ans+='0'+i;
                break;
            }
        }
    }
    bool ok=true;
    
    while(ans.size()<=8){
        cout<<"? "<<ans<<'4';
        for(int j=0;j<13-ans.size();j++){
            cout<<9;
        }
        cout<<endl;
        cin>>a;
        if(a=='Y'){
            for(int i=0;i<=4;i++){
                cout<<"? "<<ans<<i;
                for(int j=0;j<13-ans.size();j++){
                    cout<<9;
                }
                cout<<endl;
                cin>>a;
                if(a=='Y'){
                    if(i==0){
                        if(ans=="9"){
                            cout<<"? "<<10<<endl;
                            cin>>a;
                            if(a=='N'){
                                ok=false;
                                break;
                            }else{
                                ans+='0';
                                break;
                            }
                        }else{
                            string T=ans;
                            T[T.size()-1]++;
                            cout<<"? "<<T<<endl;
                            cin>>a;
                            if(a=='Y'){
                                ok=false;
                                break;
                            }else{
                                ans+='0';
                                break;
                            }
                        }
                    }else{
                        ans+='0'+i;
                        break;
                    }
                }
            }
            if(!ok) break;
        }else{
            for(int i=5;i<=9;i++){
                cout<<"? "<<ans<<i;
                for(int j=0;j<13-ans.size();j++){
                    cout<<9;
                }
                cout<<endl;
                cin>>a;
                if(a=='Y'){
                    ans+='0'+i;
                    break;
                }
            }
        }
    }
    
    if(ans=="100000000"){
        cout<<"? "<<100000001<<endl;
        cin>>a;
        if(a=='N') ans+='0';
    }
    
    cout<<"! "<<ans<<endl;
}


