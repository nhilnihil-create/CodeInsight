#include<iostream>
#include<set>
using namespace std;

int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    set<int>water;
    set<int>sugar;
    for(int i=0;100*i<=f;i++){
        for(int j=0;100*j<=f;j++){
            water.insert(100*a*i+100*b*j);
        }
    }
    for(int i=0;c*i<=f;i++){
        for(int j=0;d*j<=f;j++){
            sugar.insert(i*c+j*d);
        }
    }
    double ans=-2000000.0,tmp;
    int  wans,sans;
    for(auto  watersum : water){
        for(auto sugarsum : sugar){
            int sum=watersum+sugarsum;
            int sugarmax=watersum*e/100;
            if(sum>f||sum==0||sugarmax<sugarsum)continue;
            else{
                tmp=(double(100*sugarsum)/double(sum));
                if(tmp>ans){
                    ans=tmp;
                    wans=sum;
                    sans=sugarsum;
                }
            }
        }
    }
    cout<<wans<<" "<<sans<<endl;
    return 0;

}