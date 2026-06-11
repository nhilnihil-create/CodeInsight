#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

bool ani[200010];
int n;
string s;
void init(int i){
    if(s[0]=='o'){
        if(i==0){
            ani[0]=true;
            ani[1]=true;
            ani[n-1]=true;
        }
        else{
            if(i==1){
                ani[0]=true;
                ani[1]=false;
                ani[n-1]=false;
            }
            else{
                if(i==2){
                    ani[0]=false;
                    ani[1]=false;
                    ani[n-1]=true;
                }
                else{
                    ani[0]=false;
                    ani[1]=true;
                    ani[n-1]=false;
                }
            }
        }
    }
    else{
        if(i==0){
            ani[0]=true;
            ani[1]=true;
            ani[n-1]=false;
        }
        else{
            if(i==1){
                ani[0]=true;
                ani[1]=false;
                ani[n-1]=true;
            }
            else{
                if(i==2){
                    ani[0]=false;
                    ani[1]=false;
                    ani[n-1]=false;
                }
                else{
                    ani[0]=false;
                    ani[1]=true;
                    ani[n-1]=true;
                }
            }
        }
    }
}

bool judge(int j){
    if(j==n-1){
        if(s[j]=='o'){
            if(ani[j]){
                int x=ani[j-1]&ani[0];
                int y=(!ani[j-1])&(!ani[0]);
                return x||y;
            }
            else{
                int x=ani[j-1]&(!ani[0]);
                int y=(!ani[j-1])&ani[0];
                return x||y;
            }
        }
        else{
            if(!ani[j]){
                int x=ani[j-1]&ani[0];
                int y=(!ani[j-1])&(!ani[0]);
                return x||y;
            }
            else{
                int x=ani[j-1]&(!ani[0]);
                int y=(!ani[j-1])&ani[0];
                return x||y;
            }
        }
    }
    else{
        if(j==0){
            if(s[j]=='o'){
                if(ani[j]){
                    int x=ani[j+1]&ani[n-1];
                    int y=(!ani[j+1])&(!ani[n-1]);
                    return x||y;
                }
                else{
                    int x=ani[j+1]&(!ani[n-1]);
                    int y=(!ani[j+1])&ani[n-1];
                    return x||y;
                }
            }
            else{
                if(!ani[j]){
                    int x=ani[j+1]&ani[n-1];
                    int y=(!ani[j+1])&(!ani[n-1]);
                    return x||y;
                }
                else{
                    int x=ani[j+1]&(!ani[n-1]);
                    int y=(!ani[j+1])&ani[n-1];
                    return x||y;
                }
            }
        }
        else{
            if(s[j]=='o'){
                if(ani[j]){
                    int x=ani[j-1]&ani[j+1];
                    int y=(!ani[j-1])&(!ani[j+1]);
                    return x||y;
                }
                else{
                    int x=ani[j-1]&(!ani[j+1]);
                    int y=(!ani[j-1])&ani[j+1];
                    return x||y;
                }
            }
            else{
                if(!ani[j]){
                    int x=ani[j-1]&ani[j+1];
                    int y=(!ani[j-1])&(!ani[j+1]);
                    return x||y;
                }
                else{
                    int x=ani[j-1]&(!ani[j+1]);
                    int y=(!ani[j-1])&ani[j+1];
                    return x||y;
                }
            }
        }
    }
}

int main(void){
    cin>>n;
    cin>>s;
    for(int i=0;i<4;i++){
        init(i);
        for(int j=1;j<n-2;j++){
            if(s[j]=='o'){
                if(ani[j]){
                    if(!ani[j-1])ani[j+1]=false;
                    else ani[j+1]=true;
                }
                else{
                    if(!ani[j-1])ani[j+1]=true;
                    else ani[j+1]=false;
                }
            }
            else{
                if(ani[j]){
                    if(!ani[j-1])ani[j+1]=true;
                    else ani[j+1]=false;
                }
                else{
                    if(!ani[j-1])ani[j+1]=false;
                    else ani[j+1]=true;
                }
            }
        }
        bool flag=true;
        for(int j=0;j<n;j++){
            flag=flag&judge(j);
        }
        if(flag){
            for(int j=0;j<n;j++){
                if(j==n-1){
                    if(ani[j])cout<<'S'<<endl;
                    else cout<<'W'<<endl;
                }
                else{
                    if(ani[j])cout<<'S';
                    else cout<<'W';
                }
            }
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
