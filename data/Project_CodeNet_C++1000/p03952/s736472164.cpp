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


int main() {
    const long long int mod = 1000000007,INF=50000000000000;
    typedef pair<long long int,long long int>P;
	map<long long int, long long int>mp;
    priority_queue<P,vector<P>,greater<P> >mazuisushi;
    
    priority_queue<P>umaisushi;
	cout << fixed << setprecision(10);
    string str;
    long long int n,k,t,d,a,b,now=-1,tmp=0,typ=2;
    long long int x,res[200005]={};

    cin>>n>>x;
    if(n==2){
        if(x!=2){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes\n1\n2\n3"<<endl;
        }
    }else if(x<=1||x>=2*n-1){
        cout<<"No"<<endl;
    }else{
        //res[n+2]=2;
        res[n+1]=2*n-1;
        res[n]=x;
        res[n-1]=1;
        //res[n-2]=2*n-1;
        cout<<"Yes"<<endl;
        for(int i=1;i<=2*n-1;i++){
            if(res[i]==0){
                if(typ==x){typ++;}
                res[i]=typ;
                typ++;
            }
        }
        for(int i=1;i<=2*n-1;i++){
            cout<<res[i]<<endl;
        }
    }
} 
