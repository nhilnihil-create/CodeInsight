#include <bits/stdc++.h>
using namespace std;
long long n,a,b,sum,k,j;
string s;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n>>a>>b>>s;
for(int i=0;i<n;i++){
    if(s[i]=='a'){
        if(j<a+b){
            j++;
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    else if(s[i]=='b'){
        if(k<b&&j<a+b){
                k++;
                j++;
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    else cout<<"No"<<endl;
}

return 0;}

