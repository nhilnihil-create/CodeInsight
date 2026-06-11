#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(3*n);
    for(int i=0;i<3*n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    long long ans=0;
    for(int i=1;i<n*2;i+=2){
        ans+=a[i];
    }
    cout<<ans<<endl;
}