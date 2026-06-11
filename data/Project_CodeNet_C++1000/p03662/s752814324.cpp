#include <iostream>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <complex>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cctype>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <deque>
#include <stack>
#include <memory.h>
using namespace std;
#define ll long long 
int n;
vector<int> g[200005];
int d1[100005],d2[100005];
void dfs(int r,int f,int d,int dist[])
{
    dist[r]=d;
    for(int x=0;x<g[r].size();x++){
        if(g[r][x]!=f){
        	dfs(g[r][x],r,d+1,dist);
		}
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
    	int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,-1,0,d1);
    dfs(n-1,-1,0,d2);
    int ans=0;
    for(int i=0;i<n;i++){
        if(d1[i]<=d2[i]){
            ans++;
		}
        else{
        	ans--;
        }
    }
    if(ans>0){
    	cout <<"Fennec"<< endl;
	}
    else{
    	cout<<"Snuke"<<endl;
	}
    return 0;
}