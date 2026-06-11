#include <iostream>
using namespace std;

long long a[55],b[55],c[55],d[55];
int main(void){
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<m;i++){
        cin>>c[i]>>d[i];
    }
    
    for(int i=0;i<n;i++){
        long long minute=1000000000;
        int ans=-1;
        for(int j=0;j<m;j++){
            if(abs(a[i]-c[j])+abs(b[i]-d[j]) < minute){
                minute=abs(a[i]-c[j])+abs(b[i]-d[j]);
                ans=j;
            }
        }
        cout<<ans +1<<endl;
    }
    return 0;
}
