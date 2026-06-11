#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;
using ll=long long;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int ret=INT_MAX;
    for(int i=0;i<26;i++){
        int mn=INT_MAX;
        int mx=0;
        for(int j=n-1;j>=0;j--){
            if(s[j]==(char)('a'+i)){
                mn=j;
            }else if(mn==INT_MAX){
                mx=max(mx,n-j);
            }else{
                mx=max(mx,mn-j);
            }
        }
        ret=min(ret,mx);
    }
    cout<<ret<<endl;
}
