#include <iostream>
using namespace std;
long cur=1e9;
inline bool check(long x){
    cout<<"? "<<x<<endl;
    char res;
    cin>>res;
    return res=='Y';
}
int main(){
    if(check(cur))while(cur>1 && check(cur-1))cur/=10;
    else{
        while(!check(cur/=10));
        long lb=cur,ub=cur*10;
        while(ub-lb>1){
            long mid=(lb+ub)/2;
            if(check(mid*10))ub=mid;
            else lb=mid;
        }
        cur=ub;
    }
    cout<<"! "<<cur<<endl;
    return 0;
}