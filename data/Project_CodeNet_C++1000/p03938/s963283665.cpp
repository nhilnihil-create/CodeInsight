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

struct TWO{
    long long int a,b;
};

bool cmp(TWO x,TWO y){
    if(x.a!=y.a){
        return x.a<y.a;
    }else{
        return x.b<y.b;
    }
}

int main() {
    const long long int mod = 1000000007,INF=50000000000000;
    typedef pair<long long int,long long int>P;
	map<long long int, long long int>mp;
    priority_queue<P,vector<P>,greater<P> >mazuisushi;
    
    priority_queue<P>umaisushi;
	cout << fixed << setprecision(10);
    string str;
    long long int h,w,n;
    long long int a[20003],b[20003],p[20003],tmp=0,fin[10]={};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        a[i]=40000*i;
        b[i]=40000*(n+1-i);
    }
    for(int i=0;i<n;i++){
        a[p[i]]+=i;
    }
    
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
} 
