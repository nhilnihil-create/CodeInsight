#include<bits/stdc++.h>
using namespace std;
long long n,x,y,z,d,ma;
int main(){
    scanf("%d%d%d%d%d",&x,&y,&z,&d,&n);ma=min(min(4*x,2*y),z);
    cout<<min(ma*n,(n/2*d+n%2*ma))<<endl;
    return 0;
}