#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#include<list>
#define ll long long int
#define MOD 1000000007LL
using namespace std;
int main() {
    int n;
    cin>>n;
    int sum=0;
    int j;
    for(int i=1;i<=n;i++){
        sum+=i;
        if(sum>=n){
            j=i; 
            break;
        }
    }
    for(int i=1;i<=j;i++){
        if(i!=sum-n){
            cout<<i<<endl;
        }
    }
}
