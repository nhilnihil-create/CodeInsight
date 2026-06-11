#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
    // Your code here!
int n,l;
cin>>n>>l;
vector<string> vec(n);
for(int i=0;i<n;i++){
    cin>>vec[i];
}
sort(vec.begin(),vec.end());

string ans;
for(int i=0;i<n;i++)
ans+=vec[i];

cout<<ans;
}
