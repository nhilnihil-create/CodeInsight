#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

const int MAXN = 200001;
struct Edge{
    int end , upEd;
}Ed[MAXN];
bool vis1[MAXN] , vis2[MAXN];
int LTK1[MAXN] , LTK2[MAXN] , cnt[MAXN] , head[MAXN] , N , M , K , cntEd , cntLTK;
struct Queue{
    int arr[MAXN] , hd , tl;
    inline void init(){
        hd = tl = 0;
    }
    inline bool empty(){
        return hd == tl;
    }
    inline void push(int a){
        arr[tl++] = a;
    }
    inline void pop(){
        hd++;
    }
    inline int front(){
        return arr[hd];
    }
}q;
unordered_map < long long , int > m;

inline void addEd(int a , int b){
    Ed[++cntEd].end = b;
    Ed[cntEd].upEd = head[a];
    head[a] = cntEd;
}

inline void bfs1(int dir){
    q.init();
    q.push(dir);
    cntLTK++;
    vis1[dir] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        LTK1[t] = cntLTK;
        for(int i = head[t] ; i ; i = Ed[i].upEd)
            if(!vis1[Ed[i].end]){
                vis1[Ed[i].end] = 1;
                q.push(Ed[i].end);
            }
    }
}

inline void bfs2(int dir){
    q.init();
    while(!q.empty())
        q.pop();
    q.push(dir);
    cntLTK++;
    vis2[dir] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        LTK2[t] = cntLTK;
        for(int i = head[t] ; i ; i = Ed[i].upEd)
            if(!vis2[Ed[i].end]){
                vis2[Ed[i].end] = 1;
                q.push(Ed[i].end);
            }
    }
}

int main(){
    cin >> N >> M >> K;
    for(int i = 1 ; i <= M ; i++){
        int a , b;
        scanf("%d%d" , &a , &b);
        addEd(a , b);
        addEd(b , a);
    }
    for(int i = 1 ; i <= N ; i++)
        if(!vis1[i])
            bfs1(i);
    memset(head , 0 , sizeof(head));
    cntLTK = cntEd = 0;
    for(int i = 1 ; i <= K ; i++){
        int a , b;
        scanf("%d%d" , &a , &b);
        addEd(a , b);
        addEd(b , a);
    }
    for(int i = 1 ; i <= N ; i++)
        if(!vis2[i])
            bfs2(i);
    for(int i = 1 ; i <= N ; i++)
        m[LTK1[i] * 200000ll + LTK2[i]]++;
    for(int i = 1 ; i <= N ; i++)
        printf("%d " , m.find(LTK1[i] * 200000ll + LTK2[i])->second);
    return 0;
}