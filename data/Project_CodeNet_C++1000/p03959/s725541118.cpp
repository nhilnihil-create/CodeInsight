#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;

long long int num[2000000]={};

int main() {
    const long long int mod = 1000000007,INF=50000000000000;
    typedef pair<long long int,long long int>P;
	map<long long int, long long int>mp;
    long long int n,t[200001],a[200001],res[200001]={},fin=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    res[1]=t[1];
    res[n]=a[n];
    if(t[1]>a[1]||t[n]<a[n]){
        cout<<0<<endl;
        return 0;
    }
    for(int i=2;i<=n;i++){
        if(t[i]>t[i-1]){
            if(a[i]<t[i]){
                cout<<"0"<<endl;
                return 0;
            }else{
                res[i]=t[i];
            }
        }
    }
    for(int i=n-1;i>=1;i--){
        if(a[i]>a[i+1]){
            if(a[i]>t[i]){
                cout<<"0"<<endl;
                return 0;
            }else{
                res[i]=a[i];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(res[i]==0){
            fin*=min(a[i],t[i]);
            fin%=mod;
        }
    }
    cout<<fin%mod<<endl;
} 
