#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;


int main() {

int n,a,b;
string s;
cin>>n>>a>>b>>s;
int foreign=0,japan=0,sum=0;
Vec vec(n,0);
for(int i=0;i<n;i++){
    if(sum>=a+b){
        break;
    }
    if(s.at(i)=='a'){
        sum++;
        japan++;
        vec.at(i)=1;
    }
    else if(s.at(i)=='b' && foreign<b){
        foreign++;
        sum++;
        vec.at(i)=1;
    }

}
for(int i=0;i<n;i++){
    if(vec.at(i)==0){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
}
 
}