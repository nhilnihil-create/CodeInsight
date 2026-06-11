#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    int max=0;
    int num;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        if(a[i]>max){
            max=a[i];
            num=i;
        }
    }
    cout<<a[num]+b[num]<<endl;

    return 0;
}