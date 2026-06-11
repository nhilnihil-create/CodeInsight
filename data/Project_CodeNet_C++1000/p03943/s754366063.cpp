#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v(3);
    cin>>v[0]>>v[1]>>v[2];
    sort(v.begin(),v.end());
    if(v[0]+v[1]==v[2]){
        cout<<"Yes"<<endl;
    }
    else
    cout<<"No"<<endl;
}