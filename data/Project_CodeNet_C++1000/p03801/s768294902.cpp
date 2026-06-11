#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main(void){
    int n, z=0;
    ll a[100000], b[100000], c[100000];
    vector<int> v;
    cin>>n;
    v.push_back(0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>a[z]){
            z=i;
            v.push_back(i);
        }
        b[i]=0;
        c[i]=0;
    }
    for(int i=0;i<n;i++){
        if(a[i]<=a[0]){
            b[0]+=a[i];
            continue;
        }
        int l=0, r=v.size()-1;
        while(l+1<r){
            int m=(l+r)/2;
            if(a[v[m]]<=a[i]){
                l=m;
            }else{
                r=m;
            }
        }
        c[l]++;
        b[v[r]]+=a[i]-a[v[l]];
    }
    for(int i=v.size()-1;i>=0;i--){
        if(i<v.size()-1)c[i]+=c[i+1];
        if(i>0){
            b[v[i]]+=c[i]*(a[v[i]]-a[v[i-1]]);
        }else{
            b[v[i]]+=c[i]*a[v[i]];
        }
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<endl;
    }
}
