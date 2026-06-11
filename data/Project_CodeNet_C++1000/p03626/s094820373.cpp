#include<iostream>
#include<math.h>
#include<vector>
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
    int p=pow(10,9)+7,ans;
    int N;cin>>N;
    string S1,S2;cin>>S1>>S2;
    int i=0,front;
    if(S1[i]==S2[i]){
        ans=3;
        i++;
        front=0;
    }
    else{
        ans=6;
        i+=2;
        front=1;
    }
    while(i<N){
        if(S1[i]==S2[i]){
            if(front==0)ans=(2*ans)%p;
            front=0;
            i++;
        }
        else{
            if(front==0)ans=(2*ans)%p;
            else ans=(ans+(ans+ans)%p)%p;
            front=1;
            i+=2;
        }
    }
    cout<<ans<<endl;
    return 0;
}