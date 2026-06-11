
#include <bits/stdc++.h>
using namespace std;
//#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
//srandom((unsigned long)time(NULL));

long long N,T;
cin>>N>>T;
vector<long long> t;
long long sum;
for(long long i=0;i<N;i++){
    long long x;
    cin>>x;
    t.emplace_back(x);
}
//t1 t2  (t2-t1)+T
//t1 t2 t3  (t2-t1)+(t3-t2)+T

for(long long i=0;i<N-1;i++){
    if(t[i+1]-t[i]>=T){
        sum+=T;
    }else{
        sum+=t[i+1]-t[i];
    }

}
cout<<sum+T<<endl;


return 0;
}