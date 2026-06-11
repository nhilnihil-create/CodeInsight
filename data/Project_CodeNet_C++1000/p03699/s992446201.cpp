#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    long long sum=accumulate(s.begin(),s.end(),0LL);
    sort(s.begin(),s.end());
    if(sum%10!=0) cout<<sum<<endl;
    else{
        for(int i=0;i<n;i++){
            if(s[i]%10!=0){
                cout<<sum-s[i]<<endl;
                return 0;
            }
        }
        cout<<0<<endl;
    }
}