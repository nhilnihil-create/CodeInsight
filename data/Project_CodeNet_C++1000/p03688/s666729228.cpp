#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<tuple>
#include<set>


#define MOD 1000000007
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back

typedef long long ll;

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    rep(i,0,N)cin>>A[i];
    int s[2][2]={{-1,-1},{-1,-1}};
    

    rep(i,0,N){
        if(s[0][0]!=A[i] && s[0][1]==-1){
            s[0][0]=A[i];
            s[0][1]=1;
        }
        else if(s[0][0]==A[i]){
            s[0][1]++;
        }
        else if(s[1][0]!=A[i] && s[1][1]==-1){
            s[1][0]=A[i];
            s[1][1]=1;
        }
        else if(s[1][0]==A[i]){
            s[1][1]++;
        }
        else{
            cout<<"No"<<endl;
            return 0;
        }

    }
    bool ok=false;
    if(abs(s[0][0]-s[1][0])!=1 && s[1][0]!=-1){
        cout<<"No"<<endl;
        return 0;
    }

    if((s[0][0]-s[1][0])<0 && s[1][0]!=-1){
        swap(s[0][0],s[1][0]);
        swap(s[0][1],s[1][1]);
    }


    if(s[1][0]==-1){
        if(s[0][0]*2<=N || s[0][0]==N-1 || s[0][0]==1){
            cout<<"Yes"<<endl;
            return 0;
        }
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }

    else{
        if((N-s[1][1])>=(s[0][0]-s[1][1])*2 && (s[0][0]-s[1][1])>0){
            cout<<"Yes"<<endl;
            return 0;
        }
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    
    return 0;
}