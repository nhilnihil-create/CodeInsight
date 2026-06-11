#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

int main() {
    int n,cnt=0;
    cin>>n;
    if(n==1){
        cout<<"1"<<"\n";
        return 0;
    }
    else if(n==2){
        cout<<"2"<<"\n";
        return 0;
    }
    else{
        for(int i=1;;i++){
            cnt+=i;
            if(cnt==n){
                for(int j=1;j<i+1;j++){
                cout<<j<<"\n";
                }
                return 0;
            }
            else if(cnt>n){
                cnt=cnt-n;
                for(int k=1;k<i+1;k++){
                    if(k==cnt)
                        continue;
                    else
                        cout<<k<<"\n";
            }
            return 0;
        }
        
    }
    }
    
}