#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        result+=2*(min(abs(0-v[i]),abs(k-v[i])));
    }
    cout<<result;
}