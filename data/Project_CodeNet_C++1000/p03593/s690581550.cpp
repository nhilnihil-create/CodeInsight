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
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

int h,w;
char board[110][110];

int main(void){
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>board[i][j];
        }
    }
    map<char,int>m;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            m[board[i][j]]++;
        }
    }
    if((h%2==0)&&(w%2==0)){
        for(auto itr=m.begin();itr!=m.end();++itr){
            int x=itr->second;
            if(x%4!=0){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
    }
    else{
        if((w%2==1)&&(h%2==1)){
            int num=h*w-h-w+1;
            int c=0;
            for(auto itr=m.begin();itr!=m.end();++itr){
                int x=(itr->second)/4;
                c+=4*x;
                itr->second=(itr->second)-4*x;
            }
            if((h!=1&&w!=1)&&num!=c){
                cout<<"No"<<endl;
                return 0;
            }
            for(auto itr=m.begin();itr!=m.end();++itr){
                if(itr->second==0)continue;
                int x=(itr->second)/2;
                itr->second=(itr->second)-2*x;
            }
            int odd=0;
            for(auto itr=m.begin();itr!=m.end();++itr){
                if(itr->second==0)continue;
                if(itr->second==1)odd++;
            }
            if(odd==1)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else{
            int num=0;
            if(h%2==0)num=h*w-h;
            else num=h*w-w;
            int c=0;
            for(auto itr=m.begin();itr!=m.end();++itr){
                int x=(itr->second)/4;
                itr->second=(itr->second)-4*x;
                c+=4*x;
            }
            if(((h!=1)&&(w!=1))&&num!=c){
                cout<<"No"<<endl;
                return 0;
            }
            for(auto itr=m.begin();itr!=m.end();++itr){
                if(itr->second==0)continue;
                int x=(itr->second)/2;
                itr->second=(itr->second)-2*x;
            }
            int odd=0;
            for(auto itr=m.begin();itr!=m.end();++itr){
                if(itr->second==0)continue;
                if(itr->second==1)odd++;
            }
            if(odd==0)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}