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
    long long int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    for(long long int i=0;i<=n-1;i++){
        
        if(a-(n-1-2*i)*c-(n-1-i)*(d-c)<=b&&b<=a-(n-1-2*i)*c+(i)*(d-c)){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
} 
