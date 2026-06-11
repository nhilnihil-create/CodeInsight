#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1000000000000
#define MOD 1000000007

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    int n,a,b;
    string s;
    cin>>n>>a>>b>>s;
    int cntr=0, bcntr=0;
    for(int i=0; i<n; i++){
        if(s[i]=='a'){
            if(cntr<a+b){
                cntr++;
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else if(s[i]=='b'){
            if(cntr<a+b && bcntr<b){
                cntr++;
                bcntr++;
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}