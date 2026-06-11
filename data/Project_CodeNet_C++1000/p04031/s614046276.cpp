#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    float sum=0;
    for(int i=0;i<num.size();i++){
        sum+=num[i];
    }
    int average=round((sum)/n);
    
    int result=0;
    for(int i=0;i<num.size();i++)
    {
        result+=((num[i]-average)*(num[i]-average));
    }
    cout<<result;
}