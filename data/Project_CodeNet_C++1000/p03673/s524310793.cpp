#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    deque<int>a;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if((n%2==0&&i%2!=0)||(n%2!=0&&i%2==0)){
            a.push_front(k);
        }else{
            a.push_back(k);
        }
    }
    for(int i=0;i<n;i++){
        if(i!=n-1)cout<<a[i]<<" ";
        else cout<<a[i]<<endl;
    }
    return 0;
}