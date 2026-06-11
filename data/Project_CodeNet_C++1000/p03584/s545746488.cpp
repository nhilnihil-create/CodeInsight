#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#include <cmath>
#include <map>
using namespace std;
using P=pair<int,int>;
using lint=long long;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    lint ret=0;
    for(int i=0;i<n;i++){
        bool ok=true;
        for(int j=0;j<30;j++){
            if(((a[i]>>j)&1)&&(!((k>>j)&1))){
                ok=false;
            }
        }
        if(ok)ret+=b[i];
    }
    int now=0;
    while(k>=(1<<now)){
        lint cnt=0;
        if((1<<now)&k){
            for(int i=0;i<n;i++){
                bool ok=true;
                if(a[i]&(1<<now))ok=false;
                for(int j=now;j<30;j++){
                    if(((a[i]>>j)&1)&&(!((k>>j)&1)))ok=false;
                }
                if(ok)cnt+=b[i];
            }
        }
        ret=max(ret,cnt);
        now++;
    }
    cout<<ret<<endl;
}