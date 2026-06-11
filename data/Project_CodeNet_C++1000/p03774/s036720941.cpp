#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int n,m,min=2000000000,f=0;
    cin>>n>>m;
    vector<long long int>a(1000);
    vector<long long int>b(1000);
    vector<long long int>c(1000);
    vector<long long int>d(1000);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<m;i++){
        cin>>c[i]>>d[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((abs(a[i]-c[j])+abs(b[i]-d[j]))<min){
                min=(abs(a[i]-c[j])+abs(b[i]-d[j]));
                f=j+1;
            }
        }
        cout<<f<<endl;
        f=0;
        min=2000000000;
    }
    
    return 0;
}
