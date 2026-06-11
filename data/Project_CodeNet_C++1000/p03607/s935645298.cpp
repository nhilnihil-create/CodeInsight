#include<bits/stdc++.h>
using namespace std;
int main(){
int n,cnt=0;
long long a;
map<long long,bool>mp;
cin>>n;
while(n--){
    cin>>a;
    if(mp[a]){
        cnt--;
        mp[a]=0;
    }
    else{
        mp[a]=1;
        cnt++;
    }

}
cout<<cnt;
}