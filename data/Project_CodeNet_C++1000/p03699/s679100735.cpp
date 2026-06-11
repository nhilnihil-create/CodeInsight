#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    if(sum%10!=0)cout<<sum<<endl;
    else {
        for(int i=0;i<n;i++){
            sum-=a[i];
            if(sum%10!=0){
                cout<<sum<<endl;
                return 0;
            }else {
                sum+=a[i];
            }
        }
        cout<<0<<endl;
    }

    return 0;
}