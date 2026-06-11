#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<cstring>
#define INF 1e9+10
using namespace std;
set <int> paper;
int n,x;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(paper.count(x))
            paper.erase(x);
        else
            paper.insert(x);
    }
    printf("%lu",paper.size());
}
