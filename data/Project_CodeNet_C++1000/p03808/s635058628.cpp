#include <iostream>
using namespace std;
typedef long long ll;
ll n,s[100000],tot,N;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        tot+=s[i];
    }
    N=n*(n+1)/2;
    if(tot%N!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    N=tot/N;
    tot=0;
    for(int i=1;i<n;i++){
        s[i-1]=s[i]-s[i-1]-N;
        if(-s[i-1]%n!=0||s[i-1]>0){
            cout<<"NO"<<endl;
            return 0;
        }
        tot+=-s[i-1]/n;
    }
    if(tot<=N){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
