#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long h,w,d;
    cin>>h>>w;
    string c[h];
    f(i,0,h){
        cin>>c[i];
    }
    f(i,0,2*h){
        d=i/2;
        cout<<c[d]<<endl;
    }
    return 0;
}
