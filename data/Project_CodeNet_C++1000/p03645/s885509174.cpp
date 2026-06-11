#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<set>
#include<list>
#include<cstring>
#include<cctype>
#include<cmath>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
using ll = long long;

int main(void){
    int n,m;
    cin >> n >> m;
    
    int a[m],b[m];
    vector<int> v(n+1,0);
    for(int i = 0;i < m;i++){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        if(b[i] == n-1)v[a[i]]++;
    }

    bool check = false;
    for(int i = 0;i < m;i++){
        if(a[i] == 0){
            if(v[b[i]] > 0)check = true;
        }
    }
    
    if(!check)cout << "IM";
    cout << "POSSIBLE" << endl;
}