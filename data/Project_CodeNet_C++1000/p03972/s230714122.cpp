#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long lint;

int main(){
    int W,H;
    int px=1,py=1;
    cin >> W >> H;
    pair<lint,bool> *edge;
    edge=new pair<lint,bool>[W+H];
    for(lint i=0;i<W+H;i++){
        lint L;
        cin >> L;
        edge[i]=make_pair(L,i<W);
    }
    sort(edge,edge+W+H);

    lint cost=0;
    for(int j=1;j<=W+H;j++){
        if(edge[W+H-j].second){
            cost+=edge[W+H-j].first*px;
            py++;
        }else{
            cost+=edge[W+H-j].first*py;
            px++;
        }
    }

    cout << cost << endl;

    return 0;
}