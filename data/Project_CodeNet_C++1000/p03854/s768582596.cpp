#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<bool> ok(n+1,false);
    ok[0]=true;
    for(int i=0;i<n;i++){
        if(!ok[i]) continue;
        if(i+5<=n&&s.substr(i,5)=="dream") ok[i+5]=true;
        if(i+7<=n&&s.substr(i,7)=="dreamer") ok[i+7]=true;
        if(i+5<=n&&s.substr(i,5)=="erase") ok[i+5]=true;
        if(i+6<=n&&s.substr(i,6)=="eraser") ok[i+6]=true;
    }
    if(ok[n]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}