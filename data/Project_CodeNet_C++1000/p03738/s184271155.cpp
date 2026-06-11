#include<bits/stdc++.h>
#define endl  "\n"
#define ll long long
#define PI acos(-1.0)
#define test cout<<"\n****\n"
#define precise fixed(cout);cout<<setprecision(12)
#define fast  ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using  namespace  std;


int main(){
    string a,b;
    cin>>a>>b;

    ll siza = a.size();
    ll sizb = b.size();

    if(siza>sizb){
        cout<<"GREATER";
    } else if(siza<sizb){
        cout<<"LESS";
    } else{

        bool flag = true;
        for(ll i=0;i<sizb;i++){
            if(a[i] == b[i]){
                continue;
            } else if(a[i] > b[i]){
                cout<<"GREATER";
                return 0;
            } else{
                cout<<"LESS";
                return 0;
            }
        }
        
            cout<<"EQUAL";
        
    }
    
    return 0;
}
