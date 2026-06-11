#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;

int n;
const int mod=1000000007;
int a[100010];

int kaijo(LL x){
    if(x==0)return 1;
    else return (x*kaijo(x-1))%mod;
}
int main(){
    int cut=0;
    LL ans=1;
    
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];	
    for(int i=0;i<n-1;i++){
        if(a[i]<=2*(i-cut)){
	   ans=(ans*(i+1-cut))%mod;
	   cut++;
        }
    }
    cout<<(ans*kaijo(n-cut))%mod<<endl;
    return 0;
}