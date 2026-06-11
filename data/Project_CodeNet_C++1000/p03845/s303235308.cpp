#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
    long long int n,m,sum=0;
    cin>>n;
    vector<long long int>t(1000);
    vector<long long int>a(1000);
    vector<long long int>b(1000);
    for(long long int i=0;i<n;i++){
        cin>>t[i];
        sum+=t[i];
    }
    cin>>m;
    for(long long int i=0;i<m;i++){
        cin>>a[i]>>b[i];
    }
    for(long long int i=0;i<m;i++){
        cout<<sum-t[a[i]-1]+b[i]<<endl;
    }
    return 0;
}
