#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;

int main(){

    vector<int>a(1000000);
    vector<pair <int,int>>b(1000000);
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    if(a[0]==a[1]+a[2]){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
