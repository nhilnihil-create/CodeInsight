#include <iostream>
#include <algorithm>
#include <queue>
#define MAXN 500
#define FL(i,j,k) for(ll i=j;i<k;++i)
using namespace std;
typedef long long int ll;
ll a,b,c,d,e,f,g;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>a>>b;
    char ab;
    int bc;
    FL(i, 0, a)FL(j, 0, b){
        string s;cin>>s;
        if(s=="snuke"){
            ab=(char)(j+'A'),bc=i+1;
        }
    }
    cout<<ab<<bc;
}
