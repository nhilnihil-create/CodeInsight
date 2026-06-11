#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >> n;
int output =0;
vector<int>num(n);
for(int i=0;i<n;i++){
cin >> num.at(i);
}
for(int i=0;i<n;i++){
int p = num.at(i);
if(num.at(p-1)==i+1)
output++;
}
output /= 2;
cout<<output<<endl;
}