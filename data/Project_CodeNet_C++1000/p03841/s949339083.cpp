#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <string.h>
#include <string>
#include <set>
#include <memory.h>
#include <functional>
#include <bitset>
using namespace std;
#define ll long long

const int N = 505;

int ret[N*N];
int x[N],cc[N];
int empSt[N*N];
void solve() {
    int n;
    scanf("%d",&n);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    for(int i=1;i<=n;++i) {
        scanf("%d",&x[i]);
        ret[x[i]] = i;
        cc[i] = i-1;
        pq.push(make_pair(x[i]-cc[i],i));
        empSt[x[i]+1] = i;
    }
    int lim = n*n;
    queue<pair<int,int> >q;
    for(int i=1;i<=lim;++i) {
        if(empSt[i]) {
            int id = empSt[i];
            if(n-id>0) {
                q.push(make_pair(n-id,id));
            }
        }
        if(ret[i]!=0) {
            continue;
        }
        while(!pq.empty()) {
            int id = pq.top().second;
            if(cc[id]==0) {
                pq.pop();
                continue;
            } else {
                break;
            }
        }
        if(pq.size()>0) {
            int id = pq.top().second;
            if(x[id]<i) {
                printf("No\n");
                return;
            }
            ret[i] = id;
            pq.pop();
            --cc[id];
            if(cc[id]>0) {
                pq.push(make_pair(x[id]-cc[id],id));
            }
        }
        if(ret[i]==0) {
            if(q.size()==0) {
                printf("No\n");
                return;
            }
            pair<int,int> tmp = q.front();
            q.pop();
            ret[i] = tmp.second;
            --tmp.first;
            if(tmp.first!=0) {
                q.push(tmp);
            }
        }
    }
    printf("Yes\n");
    for(int i=1;i<=lim;++i) {
        printf("%d ",ret[i]);
    }
    cout<<endl;
}

int main() {
    //freopen("/Users/gotop/Documents/ps_practice/ps_practice/input.txt", "r", stdin);
    solve();
}

