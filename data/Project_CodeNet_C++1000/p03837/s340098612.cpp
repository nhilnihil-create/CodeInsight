#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<functional>
using namespace std;

int main(){
    int N, M;
    const int INF = 1000000;
    cin >> N >> M;
    vector< tuple<int, int, int> > l(M);
    vector< vector<int> > w(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            w.at(i).at(j) = INF;
        }
    }
    for(int i=0; i<M; i++){
        int a, b, c;
      	cin >> a >> b >> c;
        a--;
        b--;
        w.at(a).at(b) = w.at(b).at(a) = c;
        l.at(i) = make_tuple(a,b,c);
    }
    //warshall floyd
    for(int k=0; k<N; k++){
        for (int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(w.at(i).at(j) > w.at(i).at(k) + w.at(k).at(j)){
                    w.at(i).at(j) = w.at(i).at(k) + w.at(k).at(j);
                }
            }
        }
    }
    int r = 0;
    for(auto i = l.begin(); i<l.end(); i++){
        int a, b, c;
        a = get<0>(*i);
        b = get<1>(*i);
        c = get<2>(*i);
        if(w.at(a).at(b) != c){
            r++;
        }
    }
    cout << r << endl;
}
