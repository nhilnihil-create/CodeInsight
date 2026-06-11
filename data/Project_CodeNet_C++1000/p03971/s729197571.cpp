#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,a,b;
string s;
int main(void){
    cin>>n>>a>>b>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            if(a+b>0){
                cout<<"Yes"<<endl;
                a--;
            }else{
                cout<<"No"<<endl;
            }
        }else if(s[i]=='b'){
            if(a+b>0&&b>0){
                cout<<"Yes"<<endl;
                b--;
            }else{
                cout<<"No"<<endl;
            }
        }else{
            cout<<"No"<<endl;
        }
    }
    
    
}
