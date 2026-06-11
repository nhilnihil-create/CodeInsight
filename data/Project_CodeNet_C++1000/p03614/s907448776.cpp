#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#define ll long long
#define INF 1e+9
#define MOD 1000000007
using namespace std;

int main(){
    int N;
    cin >> N ;
    int p[N];
    for(int i=0; i<N; i++){
        cin >> p[i];
        p[i]--;
    }
    
    int ans=0;
    for(int i=0; i<N-1; i++){
        if(p[i]==i){
            swap(p[i],p[i+1]);
            ans++;
        }
    }
    
    if(p[N-1]==N-1){
        ans++;
    }
    
    cout<<ans<<endl;
    return 0;
}
