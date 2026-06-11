#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;
int main(){

    string a[3];
    int next=0;
    char buf;
    cin>>a[0]>>a[1]>>a[2];
    for(int i=0;i<3;i++){
        reverse(a[i].begin(),a[i].end());
    }
    while(true){
        if(a[0].empty()&&next==0){
            cout<<"A"<<endl;
            break;
        }else if(a[1].empty()&&next==1){
            cout<<"B"<<endl;
            break;
        }else if(a[2].empty()&&next==2){
            cout<<"C"<<endl;
            break;
        }
        buf=a[next].back();
        a[next].pop_back();
        if(buf=='a'){
            next=0;
        }else if(buf=='b'){
            next=1;
        }else{
            next=2;
        }
        
    }
    return 0;
}
