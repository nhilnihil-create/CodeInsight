#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int a[30];
int main(void){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        a[s[i]-'a']++;
    }
    for(int i=0;i<30;i++){
        if(a[i]%2==0){
            
        }else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    
}
