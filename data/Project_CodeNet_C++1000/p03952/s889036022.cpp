#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()

const int MOD = 1000000007;


//いろんなstlの使い方　https://qiita.com/tukejonny/items/f4013547df761a0b3523
//http://y-mazun.hatenablog.com/entry/20111202/1322840281



using namespace std;

int main(){
    int N,x;
    cin>>N>>x;
    if(x==1||x==2*N-1){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        if(x==2){
            int a[2*N-1];
            a[N-2]=x+1;
            a[N-1]=x;
            a[N]=x-1;
            a[N+1]=x+2;
            queue<int>que;
            for(int i=1;i<=2*N-1;i++){
                if(i==x+1||i==x||i==x-1||i==x+2){
                    continue;
                }else{
                    que.push(i);
                }

            }
            for(int i=0;i<2*N-1;i++){
                if(i==N-2||i==N-1||i==N||i==N+1){
                    continue;
                }else{
                    a[i]=que.front();
                    que.pop();
                }
            }
            for(int i=0;i<2*N-1;i++){
                cout<<a[i]<<endl;
            }


        }else{
            int a[2*N-1];
            a[N-2]=x-1;
            a[N-1]=x;
            a[N]=x+1;
            a[N+1]=x-2;
            queue<int>que;
            for(int i=1;i<=2*N-1;i++){
                if(i==x+1||i==x||i==x-1||i==x-2){
                    continue;
                }else{
                    que.push(i);
                }

            }
            for(int i=0;i<2*N-1;i++){
                if(i==N-2||i==N-1||i==N||i==N+1){
                    continue;
                }else{
                    a[i]=que.front();
                    que.pop();
                }
            }
            for(int i=0;i<2*N-1;i++){
                cout<<a[i]<<endl;
            }
        }
    }


}




