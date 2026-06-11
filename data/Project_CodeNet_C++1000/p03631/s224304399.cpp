#include <iostream>
using namespace std;
typedef long long ll;
int main(void){
    // Your code here!
    string n;cin>>n;
    string ans;
    if(n[0]==n[2]){
        ans="Yes";
    }else{
        ans="No";
    }
    cout<<ans<<endl;
}