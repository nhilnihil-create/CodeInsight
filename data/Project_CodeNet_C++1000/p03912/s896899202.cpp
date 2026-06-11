#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m, c=0;
    int p[100002], y[100002];
    cin>>n>>m;
    for(int i=0;i<100002;i++){
        p[i]=y[i]=0;
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p[x%m]++;
        y[x]++;
    }
    c+=p[0]/2;
    p[0]%=2;
    if(m%2==0){
        c+=p[m/2]/2;
        p[m/2]%=2;
    }
    for(int i=1;i<m-i;i++){
        int z=min(p[i], p[m-i]);
        c+=z;
        p[i]-=z;
        p[m-i]-=z;
    }
    for(int i=1;i<=100000;i++){
        int z=min(p[i%m], y[i]);
        z-=z%2;
        if(z>=2){
            p[i%m]-=z;
            c+=z/2;
        }
    }
    cout<<c<<endl;
	return 0;
}