#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int>rating(9,0);
    for(int i=0;i<n;i++){
        if(v[i]>=1&&v[i]<=399){
            rating[0]++;
        }
        else
        if(v[i]>=400&&v[i]<=799){
            rating[1]++;
        }
        else
        if(v[i]>=800&&v[i]<=1199){
            rating[2]++;
        }
        else
        if(v[i]>=1200&&v[i]<=1599){
            rating[3]++;
        }
        else
        if(v[i]>=1600&&v[i]<=1999){
            rating[4]++;
        }
        else
        if(v[i]>=2000&&v[i]<=2399){
            rating[5]++;
        }
        else
        if(v[i]>=2400&&v[i]<=2799){
            rating[6]++;
        }
        else
        if(v[i]>=2800&&v[i]<=3199){
            rating[7]++;
        }
        else{
            rating[8]++;
        }
    }
    int sum1=0;
    for(int i=0;i<8;i++)
    {
        if(rating[i]>=1){
            sum1++;
        }
    }
    int min=sum1;
    int max=sum1;
    if(sum1==0){
        max+=rating[8];
        if(rating[8]>0)
            min++;
    }else{
        max+=rating[8];
    }
    cout<<min<<" "<<max;
}