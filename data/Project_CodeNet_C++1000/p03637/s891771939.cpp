#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    long long int n,ans=0,a1=0,a2=0,a4=0;
    cin>>n;
    string s="Yes";
    vector<long long int>t(1000000);
    for(int i=0;i<n;i++){
        cin>>t[i];
        if(t[i]%4==0){
            a4++;
        }
        else if(t[i]%2==0){
            a2++;
        }
        else{
            a1++;
        }
    }
    if(a2>0){
        a1++;
    }
    if(a1>a4+1){
        s="No";
    }
    cout<<s<<endl;
    return 0;
}