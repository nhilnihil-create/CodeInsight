#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#define int long long
#define double long double
using namespace std;
signed main(){
    int n;
    cin>>n;
    vector<int> t(n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>t[i]>>a[i];
    }
    
    int t_temp=1;
    int a_temp=1;
    double k;
    for(int i=0;i<n;i++){
        k=max(ceil((double)t_temp/(double)t[i]),ceil((double)a_temp/(double)a[i]));
        t_temp=(int)k*t[i];
        a_temp=(int)k*a[i];
    }
    
    cout<<t_temp+a_temp<<endl;
    return 0;
    
}