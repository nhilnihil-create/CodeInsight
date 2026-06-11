#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> al[100005];


int dfs(int i){
    vector<int> child;
    
    for (auto &it:al[i]){
        child.push_back(dfs(it));
    }
    
    sort(child.begin(),child.end(),[](int i,int j){
        return i>j;
    });
    
    int m=-1;
    for (int x=0;x<child.size();x++){
        m=max(m,child[x]+x);
    }
    
    if (child.empty()) return 0;
    else return m+1;
}
int main(){
    scanf("%d",&n);
    int temp;
    for (int x=2;x<=n;x++){
        scanf("%d",&temp);
        al[temp].push_back(x);
    }
    
    printf("%d\n",dfs(1));
}