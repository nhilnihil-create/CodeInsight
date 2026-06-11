#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>


using namespace std;


void addEdge(vector<pair<int,int> >*adjList,int u, int v, int w)
{
    adjList[u].push_back(pair<int, int>(v, w));
    adjList[v].push_back(pair<int, int>(u, w));

}

void printGraph(vector<pair<int, int> >* adjList,int V)
{
    vector<pair<int, int> >::iterator itr;
    int i;
    for (i = 0; i < V; ++i) {
        cout << i << "->";
        for (itr = adjList[i].begin(); itr != adjList[i].end(); ++itr) {
            cout << itr->first << "," << itr->second << " ";
        }
        cout << "\n";
    }
}



int main()
{
    int a,b,c,d;
    cin >>a>>b>>c>>d;
    int max;
    if (a * b > c* d) {
        cout << a * b;
    }
    else {
        cout << c * d;
    }



    
}
