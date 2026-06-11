#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long n,p=0,area=1;
    cin>>n;
    long long side[n];
    for(int i=0;i<n;i++){
        cin>>side[i];
    }
    sort(side,side+n,greater<int>());
    for(int i=0;i<n-1;i++){
        if(side[i]==side[i+1]){
            p++;
            area=area*side[i];
            i++;
        }
        if(p==2){
            cout<<area<<endl;
            return 0;
        } 
    }
    cout<<'0'<<endl;
    return 0;
}