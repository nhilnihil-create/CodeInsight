#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long int ans=0;
    vector<int>a(1000000);
    vector<pair <int,int>>b(1000000);
    for(long long int i=0;i<s.size()-1;i++){
        if(s[i]!=s[i+1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
