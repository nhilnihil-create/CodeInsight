//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <cmath>
//#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(x,n) for(int x=0;x<n;x++)

//vector//
#define vei vector<int> 
#define velli vector<long long int> 
#define pb(x) push_back(x) // 末尾にxを加える
#define pb2 pop_back() // 末尾削除
#define all(x) (x).begin(),(x).end() //イテレーター
#define be(x) (x).begin()
//auto  auto begin = v.begin()とか

typedef pair<int,int> P;  //q(p.first,p.second)

int main (){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> c(h,vector<char>(w));
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            char in;
            cin >> in;
            c[i][j] = in;
        }
    }
    REP(i,h){
        REP(k,2){
            REP(j,w){
                cout << c[i][j];
            }
            cout << endl;
        }
    }
}