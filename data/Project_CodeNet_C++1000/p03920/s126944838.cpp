#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <bitset>
#include <time.h>
#include <set>
#include <algorithm>
#define MODD 1000000007
#define ll long long
using namespace std;


int main() {
    int N;
    cin>>N;
    
    
    
    // given x, (x*(x-1))/2
    
    ll x;
    for(x=1;;x++) {
        if ((x*(x-1))/2 >= N-x) {
            break;
        }
    }

    
    
    vector<int> ans;
    ans.push_back(x);
    
    N -= x;
    int prev = x;
    while(N > 0) {
        // min(prev-1,N);
        int next = min(prev-1,N);
        ans.push_back(next);
        N-=next;
        prev=next;
    }
    
    for(int j=ans.size()-1;j>=0;j--)
        printf("%d\n",ans[j]);
    
    
    
}