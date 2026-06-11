#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n;
    long T;
    cin>>n>>T;
    vector<long> t(n);
    for(int i=0;i<n;i++) cin>>t[i];

    long sum=0;
    for(int i=0;i<=n-2;i++){
        sum+=min(T,t[i+1]-t[i]);
    }
  sum+=T;
    cout<<sum<<endl;
}    