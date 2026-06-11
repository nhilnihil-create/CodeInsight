#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    ll n,a,b;cin>>n>>a>>b;
    if((n<=1&&a!=b)||a>b){
        cout<<0<<endl;
        return 0;
    }else{
        cout<<max((b-a)*(n-2),(ll)0)+1<<endl;
        return 0;
    }
}