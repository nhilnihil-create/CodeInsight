#include <iostream>
#include <cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define reprev(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define MAX 100100
#define MAX_N 200100
#define SENTINEL 2000000000
#define MAX_B 1001001
#define NIL -1
#define MOD 1000000007
#define INF 1 << 29
#define INFTY 1000000000000000000LL
double con(int w,int s){
    if(w+s==0)return 0;
    return (double)s/(double)(w+s);
}
int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    double max=0;
    int m_w=0,m_s=0;
    rep(i,31)rep(j,31)rep(k,101)rep(l,101){
        int w1=100*a*i,w2=100*b*j,s1=c*k,s2=d*l;
        if(w1+w2+s1+s2>f || (w1+w2==0||(double)(s1+s2)/((double)(w1+w2)/100.)>e)){
            break;
        }
        if(max<=con(w1+w2,s1+s2)){
            max=con(w1+w2,s1+s2);
            m_w=w1+w2;
            m_s=s1+s2;
            }
    }
    cout<<m_w+m_s<<" "<<m_s<<endl;
}