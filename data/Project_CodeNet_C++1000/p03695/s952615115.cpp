#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n,x,takai=0;
    cin>>n;
    vector<int> rate(8);
    for(i=0;i<n;i++){
        cin>>x;
        if(x>=3200){
            takai++;
            continue;
        }
        for(j=0;j<8;j++){
            if(x>=400*j&&x<400*(j+1)){
                rate[j]++;
                break;
            }
        }
    }
    cerr<<takai<<endl;
    int min=0,max;
    for(i=0;i<8;i++){
        if(rate[i]>=1)min++;
    }
    if(min==0){
        min=1;
        max=takai;
    }else{
        max=min+takai;
    }
    cout<<min<<" "<<max<<endl;
}