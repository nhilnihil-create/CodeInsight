#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
    long long int n,ac=0,ans=0;
    cin>>n;
    vector<long long int>a(10000000);
    vector<long long int>b(10000000);
    vector<long long int>c(10000000);
    for(int i=0;i<(n+1)/2;i++){
        cin>>a[i]>>b[i];
        c[2*i]=a[i];
        c[2*i+1]=b[i];
    }
    sort(a.begin(),a.end(),greater<>());
    sort(b.begin(),b.end(),greater<>());
    sort(c.begin(),c.end(),greater<>());
    for(int i=0;i<n;i++){
        if(c[i]==a[ac]){
            if(i%2!=0){
                if(n%2==0){

                }
                else{
                    ans++;
                }
            }
            else{
                if(n%2==0){
                    ans++;
                }
                else{
                }
            }
            ac++;
        }
    }
    cout<<ans<<endl;


    return 0;
}