#include <iostream>
using namespace std;

int main() {
    int n;cin>>n;
    int tmp,a[3];
    for(int i=0;i<3;++i){
    a[i]=0;
    }
    
    for(int i=0;i<n;++i){
        cin>>tmp;
        if(tmp%4==0)a[0]++;
        else if(tmp%2==0)a[1]++;
        else a[2]++;
    }
    if(a[2] - 1>a[0]||(a[2] - 1==a[0]&&a[1]>0))cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

	return 0;
}