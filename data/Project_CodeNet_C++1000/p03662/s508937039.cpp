#include <iostream>
#include <queue>
#include <vector>
#include <utility>
//#include <list>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> graph[n+1];//配列の配列的なもの
    for(int i=0;i<n-1;i++){
        int a=0,b=0;
        cin >> a;
        cin >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
//    cout <<"OK" <<endl;
    int mini[n+1];
    for(int i=0;i<n+1;i++){
        mini[i]=2147483647;
    }
    int s=1;
    queue< pair<int,int> > que;
    mini[s]=0;
    que.push(make_pair(s,0));
    while(!que.empty()){
        pair<int,int> curr = que.front();
        que.pop();
        for(int to : graph[curr.first]){
            if(mini[to]>curr.second+1){
                que.push(make_pair(to,curr.second+1));
                mini[to]=curr.second+1;
            }
        }
    }
//        cout <<"OK" <<endl;

    int mini2[n+1];
    for(int i=0;i<n+1;i++){
        mini2[i]=2147483647;
    }
    int e=n;
//    queue<pair<int,int>> que;
    mini2[e]=0;
    que.push(make_pair(e,0));
    while(!que.empty()){
        pair<int,int> curr = que.front();
        que.pop();
        for(int to : graph[curr.first]){
            if(mini2[to]>curr.second+1){
                que.push(make_pair(to,curr.second+1));
                mini2[to]=curr.second+1;
            }
        }
    }
//        cout <<"OK" <<endl;

    int cntF=0;
    int cntS=0;
    for(int i=1;i<=n;i++){
//        cout <<mini[i] << " " <<mini2[i] <<endl;
        if(mini[i]<=mini2[i]){
            cntF++;
        }else{
            cntS++;
        }
    }
//    cout <<cntF << " " <<cntS <<endl;
    if(cntF>cntS){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
    return 0;
}