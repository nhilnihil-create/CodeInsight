#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;





int main(){
    ll H,W,h,w;
    cin>>H>>W>>h>>w;
    if(H%h==0 && W%w==0){
        cout<<"No"<<endl;
    }
    else if(H%h!=0){
        cout<<"Yes"<<endl;
        vector<ll> a(h,0);
        a[0]=100001;
        for(int i=1;i+1<h;i++){
            a[i]=1;
        }
        a[h-1]-=100001+h;
        for(int i=0;i<H;i++){
            for(int t=0;t<W;t++){
                cout<<a[i%h];
                if(t+1!=W){cout<<" ";}
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Yes"<<endl;
        vector<ll> a(w,0);
        a[0]=100001;
        for(int i=1;i+1<w;i++){
            a[i]=1;
        }
        a[w-1]-=100001+w;
        for(int i=0;i<H;i++){
            for(int t=0;t<W;t++){
                cout<<a[t%w];
                if(t+1!=W){cout<<" ";}
            }
            cout<<endl;
        }
    }
    
    
    
    
    return 0;
}

