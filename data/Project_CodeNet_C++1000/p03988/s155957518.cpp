#include <iostream>
using namespace std;
int main(void){
    int n,a,c[100],m=0,l;
    cin>>n;
    fill(c, c+n, 0);
    for(int i=0;i<n;i++){
        cin>>a;
        c[a]++;
        m=max(m, a);
    }
    if(n==2){
        cout<<"Possible"<<endl;
        return 0;
    }
    l=(m+1)/2;
    for(int i=m;i>0;i--){
        int d=c[i];
        if(m==n-1){
            if(d>2||(i>l&&d!=2)||(i==l&&d==0)||(i<l&&d!=0)){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }else{
            if((i>l&&d<2)||(i==l&&d!=1+m%2)||(i<l&&d!=0)){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
}
