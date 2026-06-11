#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string s;cin>>s;
    long long n=(int)s.length();
    vector<long long> num(30,0);
    for(int i=0;i<n;i++){
        int buf=s[i]-'a';
        num[buf]++;
    }
    long long sum=(n*(n-1)/2)+1;
    for(int i=0;i<30;i++){
        sum=sum-(num[i]*(num[i]-1))/2;
    }
    cout<<sum<<endl;
    return 0;
}