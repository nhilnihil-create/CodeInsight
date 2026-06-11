#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    set<int> chair;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        for(int i=l;i<=r;i++){
            chair.insert(i);
        }
    }
    cout<<chair.size()<<endl;


    return 0;
}