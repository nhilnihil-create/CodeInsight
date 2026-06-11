#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<limits>
#include<bitset>
#include<array>
#include<numeric>
#include<iomanip>
#include<functional>
#include<deque>

using namespace std;
typedef long long int ll;

#define C cout<<
#define E <<endl
#define CE cout<<endl
#define pb push_back

ll n,m,a,b,c,x,y,z,aa[200010],ab[200010],ac[200010];
ll xa,xb,ua,ub;
bool r,ra,rb,rc[200010];
string s,sa,sb,sc;
char ca,cb,cc,cd[1010][1010];
vector<ll> va,vb,vc,vd,ve,vaa,vbb;
set<ll> st;

#define SIZ 200010


vector<vector<ll>> dp;

vector<vector<ll>> v2vec(int x,int y,int value=0){ return vector<vector<ll>>(y,vector<ll>(x,value)); }

template<typename MAIN>
ostream & operator<<(ostream & osys,vector<MAIN> vtar){
    osys<<"[";
    for(int i=0;i<vtar.size();i++)osys<<vtar[i]<<(i==vtar.size()-1 ? "":",");
    osys<<"]";
    return osys;
}

template<typename MAIN>
void intovec(MAIN * star,vector<MAIN> & vtar,int size){
    vtar.clear();
    for(int i=0;i<size;i++){
        vtar.pb(star[i]);
    }
}

int main(){
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>aa[i];  
    }

    intovec(aa,va,n);
    vb=vector<ll>(n);
    vb[n-1]=va[n-1];
    for(int i=n-2;i>=0;i--){
        vb[i]=max(vb[i+1],va[i]);
        
    }
    //m=0;
    c=0;
    a=0;
    for(int i=0;i<n;i++){
        vb[i]-=va[i];
        if(vb[i]>c){
            c=vb[i];
            a=1;
        }
        else if(vb[i]==c){
            a++;
        }
    }
    C a E;

    
}
