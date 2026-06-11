#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
const int MAX = 100100; 

vector<int> L[MAX];
pair<int, int> K[MAX];
int isvisit[MAX];
int pnum;
bool finish;
set<int> m;
deque<int> path;


int main(){
    int N,M;
    cin >> N >> M;
    REP(i,M){
        int a,b;
        cin >> a >> b;
        a--, b--;
        L[a].push_back(b);
        L[b].push_back(a);
        //int ka = K[a].first;
        //int kb = K[b].first;
    }
    
    int front = 0;
    int back = L[0][0];
    m.insert(front);
    m.insert(back);
    path.push_front(front);
    path.push_back(back);
    pnum += 2;
    while(1){
        bool update = false;
        for(int i = 0; i < L[front].size(); i++){
            int next = L[front][i];
            if(m.find(next) == m.end()){
                m.insert(next);
                front = next;
                path.push_front(front);
                pnum++;
                update = true;
                break;
            }
        }
        for(int i = 0; i < L[back].size(); i++){
            int next = L[back][i];
            if(m.find(next) == m.end()){
                m.insert(next);
                back = next;
                path.push_back(back);
                pnum++;
                update = true;
                break;
            }
        }
        if(update == false) break;
    }



    printf("%d\n", pnum);
    REP(i,pnum){
        printf("%d ", path.front()+1);
        path.pop_front();
    }
    printf("\n");

    return 0;
}
