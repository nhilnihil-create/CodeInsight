#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    int n,ans=-1,c=0;
    cin>>n;
    vector<int>a(1000000);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[c]==2){
            ans=i+1;
            break;
        }
        else{
            c=a[c]-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
