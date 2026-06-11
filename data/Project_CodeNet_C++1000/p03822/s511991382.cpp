#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<numeric>
#include<iomanip>
#include<utility>
#include<cstdlib>
#include<typeinfo>
#include<stack>
#include<cassert>
#include<functional>
#define int long long int
#define double long double
using namespace std;
#define INT_MAX 1000000007
#define INF 1000000000000000007
const int MAX_N = 1 << 17;
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
#define maxn 100001

typedef struct {
    std::vector<int> nextnode;
    int weight;
} tree;

int seek(std::vector<tree> &a,int now){
    if(a[now].nextnode.size() == 0) return 0;
    std::vector<int> t;
    for(int i = 0; i < a[now].nextnode.size(); i++){
        t.push_back(seek(a,a[now].nextnode[i]));
    }
    std::sort(t.begin(),t.end());
    int w = t[0];
    for(int i = 0; i < t.size();i++){
        w = max(w + 1, t[i] + 1);
    }
    return w;
}


signed main()
{
int n;
std::cin >> n;
std::vector<tree> a(n);
a[0].weight = 0;
for(int i = 1; i < n; i++){
    int temp;
    a[i].weight = 0;
    std::cin >> temp;
    temp--;
    a[temp].nextnode.push_back(i);
}
int out = seek(a,0);
std::cout << out << std::endl;

return 0;
}