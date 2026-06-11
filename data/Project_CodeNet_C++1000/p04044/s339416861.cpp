#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
        int n,l;
        cin>>n>>l;
        vector<string> z(n);
        for(int i=0;i<n;i++)
        cin>>z[i];
        sort(z.begin(),z.end());
        for(int i=0;i<n;i++)
        cout<<z[i];
        cout<<endl;
}