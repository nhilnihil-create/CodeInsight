#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int main(){
    string S;cin>>S;
    int N=S.size();
    int g=0,p=0,win=0,lose=0;
    for(int i=0;i<N;i++){
        if(p==g){
            g++;
            if(S[i]=='p')lose++;
        }
        else{
            p++;
            if(S[i]=='g')win++;
        }
    }
    cout<<win-lose<<endl;
    return 0;
}