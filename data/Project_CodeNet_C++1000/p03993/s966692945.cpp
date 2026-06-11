#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
int n,a[100000],ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    for(int i=0;i<n;i++){
        if(i==a[a[i]])ans++;
    }
    cout<<ans/2<<endl;
}
