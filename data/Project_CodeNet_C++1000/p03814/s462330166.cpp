#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;
    int cnt=0;
    int z,a;
    for(int i=s.size();i>0;i--){
        if(s[i]=='Z'){
            z=i;
            break;
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            a=i;
            break;
        }
    }
    cout<<z-a+1<<endl;
    return 0;
}