#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;

char board[105][105];

int main(void){
    int h,w;
    cin>>h>>w;
    map<char,int>m;
    for(char c='a';c<='z';c++)m[c]=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>board[i][j];
            m[board[i][j]]++;
        }
    }
    if(h==1){
        if(w%2==1){
            for(char c='a';c<='z';c++){
                if(m[c]==0)continue;
                if(m[c]%4==1){
                    m[c]-=1;
                    break;
                }
                if(m[c]%4==3){
                    m[c]-=1;
                    break;
                }
            }
        }
        int num = w/2;
        for(int i=0;i<num;i++){
            for(char c='a';c<='z';c++){
                if(m[c]==0)continue;
                if(m[c]%4==2){
                    m[c]-=2;
                    break;
                }
                if(m[c]%4==0){
                    m[c]-=2;
                    break;
                }
            }
        }
        for(char c='a';c<='z';c++){
            if(m[c]!=0){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
        return 0;
    }
    if(w==1){
        if(h%2==1){
            for(char c='a';c<='z';c++){
                if(m[c]==0)continue;
                if(m[c]%4==1){
                    m[c]-=1;
                    break;
                }
                if(m[c]%4==3){
                    m[c]-=1;
                    break;
                }
            }
        }
        int num = h/2;
        for(int i=0;i<num;i++){
            for(char c='a';c<='z';c++){
                if(m[c]==0)continue;
                if(m[c]%4==2){
                    m[c]-=2;
                    break;
                }
                if(m[c]%4==0){
                    m[c]-=2;
                    break;
                }
            }
        }
        for(char c='a';c<='z';c++){
            if(m[c]!=0){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
        return 0;
    }
    if(h%2==0){
        if(w%2==0){
            int num = h*w/4;
            for(int i=0;i<num;i++){
                for(char c='a';c<='z';c++){
                    if(m[c]==0)continue;
                    if(m[c]%4==0){
                        m[c]-=4;
                        break;
                    }
                }
            }
            for(char c='a';c<='z';c++){
                if(m[c]!=0){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            cout<<"Yes"<<endl;
        }
        else{
            int num = h/2;
            for(int i=0;i<num;i++){
                for(char c='a';c<='z';c++){
                    if(m[c]==0)continue;
                    if(m[c]%4==2){
                        m[c]-=2;
                        break;
                    }
                }
            }
            num = (h*w-h)/4;
            for(int i=0;i<num;i++){
                for(char c='a';c<='z';c++){
                    if(m[c]==0)continue;
                    if(m[c]%4==0){
                        m[c]-=4;
                        break;
                    }
                }
            }
            for(char c='a';c<='z';c++){
                if(m[c]!=0){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            cout<<"Yes"<<endl;
        }
    }
    else{
        if(w%2==0){
            int num = w/2;
            for(int i=0;i<num;i++){
                for(char c='a';c<='z';c++){
                    if(m[c]==0)continue;
                    if(m[c]%4==2){
                        m[c]-=2;
                        break;
                    }
                }
            }
            num = (h*w-w)/4;
            for(int i=0;i<num;i++){
                for(char c='a';c<='z';c++){
                    if(m[c]==0)continue;
                    if(m[c]%4==0){
                        m[c]-=4;
                        break;
                    }
                }
            }
            for(char c='a';c<='z';c++){
                //cout<<m[c]<<endl;
                if(m[c]!=0){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            cout<<"Yes"<<endl;
        }
        else{
            for(char c='a';c<='z';c++){
                if(m[c]==0)continue;
                if(m[c]%4==1){
                    m[c]-=1;
                    break;
                }
                if(m[c]%4==3){
                    m[c]-=1;
                    break;
                }
            }
            int num = (h+w-2)/2;
            for(int i=0;i<num;i++){
                for(char c='a';c<='z';c++){
                    if(m[c]==0)continue;
                    if(m[c]%4==2){
                        m[c]-=2;
                        break;
                    }
                }
            }
            num = (h*w-(h+w-1))/4;
            for(int i=0;i<num;i++){
                for(char c='a';c<='z';c++){
                    if(m[c]==0)continue;
                    if(m[c]%4==0){
                        m[c]-=4;
                        break;
                    }
                }
            }
            for(char c='a';c<='z';c++){
                if(m[c]!=0){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}