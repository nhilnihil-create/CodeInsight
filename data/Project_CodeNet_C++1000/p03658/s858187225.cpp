#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    int n,k,s=0;
    cin>>n>>k;
    vector<int>a(1000000);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    for(int i=0;i<k;i++){
        s+=a[i];
    }
    cout<<s<<endl;
    
    return 0;
}
