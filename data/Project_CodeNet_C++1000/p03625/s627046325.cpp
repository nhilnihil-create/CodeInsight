#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    long long int n,h=0,w=0;
    cin>>n;
    vector<long long int>a(200000);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    for(int i=0;i<n-1;i++){
        if(h==0&&a[i]==a[i+1]){
            h=a[i];
            i++;
        }
        else if(a[i]==a[i+1]){
            w=a[i];
            break;
        }
    }
    cout<<h*w<<endl;
    return 0;
}