#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;

long long int mod=1000000007;


long long int n,k,q,a[60]={},b[5000],res,sum[2300]={},key=0;
queue<pair<long long ,long long > >que;
int main() {
    const long long int INF=99999999999999;
	map<long long int, long long int>mp;
    string str[550],red[550],blue[550];
    priority_queue<long long int>pq[4];
    priority_queue<long long int>tmp[4];
	cout << fixed << setprecision(10);
    cin>>k;
    cout<<50<<endl;
    for(int i=1;i<=min(k,50LL);i++){
        a[i]=50-i+1;
    }
    k-=50;
    if(k>0){
        for(int i=1;i<=50;i++){
            a[i]+=k/50;
        }
        k%=50;
        for(int i=1;i<=min(k,50LL);i++){
            a[i]++;
        }
    }
    for(int i=1;i<=50;i++){
        cout<<a[i]<<" ";
    }
} 
