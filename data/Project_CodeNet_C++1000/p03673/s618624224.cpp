#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(1000000);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<a[n-1]<<flush;
    for(int i=1;i<(n+1)/2;i++){
        cout<<' '<<a[n-1-2*i]<<flush;
    }
    for(int i=0;i<n/2;i++){
        cout<<' '<<a[2*i+(n%2)]<<flush;
    }
    cout<<endl;
    
    return 0;
}
