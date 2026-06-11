#include <iostream>
using namespace std;
typedef long long ll;
ll n,s[100000];
int main(void){
    cin>>n;
    for(ll i=1;i<100000;i++){
        s[i]=s[i-1]+i;
      if(n<=s[i]){
        cout<<i<<endl;
        return 0;
      }
    }
}
