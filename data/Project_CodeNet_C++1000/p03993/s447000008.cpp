#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(void){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(i=0;i<n;i++){
        cin>>vec[i];
    }
    for(i=0;i<n;i++){
        if(i==(vec[vec[i]-1]-1)){
            count1++;
        }
    }
    cout<<count1/2<<endl;
}