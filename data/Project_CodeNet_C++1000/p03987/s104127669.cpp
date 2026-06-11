#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
#include <set>
#include <limits.h>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define rip(i,n,s) for (int i=(s);i<(int)(n);i++)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> da(n);
    int x;
    rip(i,n,0){
        cin >> x;
        da[x-1]=i;
    }
    set<int> se;
    se.insert(-1);
    se.insert(n);
    long long ans=0;
    rip(i,n,0){
        auto itr=se.upper_bound(da[i]);
        ans+=(ll)(*itr-da[i])*(da[i]-*--itr)*(ll)(i+1);
        se.insert(da[i]);
    }
    printf("%lld\n",ans);
}