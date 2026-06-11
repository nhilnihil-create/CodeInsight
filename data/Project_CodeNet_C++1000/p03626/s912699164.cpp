#include <iostream>
#include<map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn=100000;

int main(){
   
    int n;
    ll mod=INF;
    ll ans=0;
    string s1,s2;
    vector<ll> v;
   
    cin >> n;
    cin >> s1;
    cin >> s2;
    
    int ite=0;
    while(ite<s1.size()){
        if(s1[ite]==s2[ite]){
            v.push_back(1);
            ite+=1;
        }else{
            v.push_back(2);
            ite+=2;
        }
    }
    
    
    rep(i,v.size()){
        if(i==0){
            if(v[i]==1){
                ans=3;
            }else{
                ans=6;
            }
        }else{
            if(v[i-1]==1){
                if(v[i]==1){
                    ans=(ans*2)%mod;
                }else{
                    ans=(ans*2)%mod;
                }
            }else{
                if(v[i]==1){
                    ans=(ans*1)%mod;
                }else{
                    ans=(ans*3)%mod;
                }
            }
        }
    }

    cout << ans<<endl;
    
    return 0;
}
