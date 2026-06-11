#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<string>
//#include<string>
//#include<sstream>
using namespace std;

typedef long long ll;
#define N 5050
int a[N]={0};
int  main(){
    ll n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);//排序，容易知道一定是最小的那几个是不需要的
    ll sum = 0;
    ll p = n;

    for(ll i=n-1; i>=0; i--){
        if(sum+a[i]<k){
            sum +=a[i];
        }
        else{
            p = i;
        }
    }
    cout<<p<<endl;
	return 0;
}