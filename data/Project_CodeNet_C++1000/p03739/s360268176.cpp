#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int n,sum=0,f=0,ans1=0,ans2=0;
    cin>>n;
    vector<long long int>a(10000000);
    vector<long long int>b(10000000);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    f=-1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(f*sum>0){

        }
        else{
            ans1+=abs(sum)+1;
            sum=f;
            a[i]+=f*(abs(sum)+1);
        }
        f*=-1;
    }
    sum=0;
    f=1;
    for(int i=0;i<n;i++){
        sum+=b[i];
        if(f*sum>0){

        }
        else{
            ans2+=abs(sum)+1;
            sum=f;
            b[i]+=f*(abs(sum)+1);
        }
        f*=-1;
    }
    if(ans2<ans1){
        ans1=ans2;
    }
    cout<<ans1<<endl;    
    return 0;
}
