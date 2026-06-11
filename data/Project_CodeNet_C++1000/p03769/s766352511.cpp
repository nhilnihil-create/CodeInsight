#include<iostream>
#include<algorithm>
using namespace std;
long long n;
int p_1[106],p_0[106];

int main(){
    cin>>n;
    n++;
    int k1=0,k2=0;
    int m=100;
    while(n>1){
        if((n&1)==1){
            p_1[k1]=m--;k1++;n--;
        }
        else{
            p_0[k2]=m--;k2++;n=n>>1;
        }
    }
    cout<<(k1+k2)*2<<endl;
    for(int i=0;i<k1;i++)
        cout<<p_1[i]<<" ";
    for(int i=k2-1;i>=0;i--)
        cout<<p_0[i]<<" ";
    int p=101-k1-k2;
    for(;p<100;p++)
        cout<<p<<" ";
    cout<<"100"<<endl;
    return 0;
}
