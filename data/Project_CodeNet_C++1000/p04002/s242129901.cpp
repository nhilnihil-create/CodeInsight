#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>

#define repeat(i,n) for (int i = 0; (i) < (n); ++ (i))

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
const ll INF = LONG_LONG_MAX;
const int MAX_P = 55555+1;



int main() {
    // insert code here...    return 0;
    //////
    // input from txt
    /*
     std::ifstream in("input.txt");
     std::cin.rdbuf(in.rdbuf());
     std::ofstream out("output.txt");
     std::cout.rdbuf(out.rdbuf());
     ////
     */
    
    int H,W,N;
    cin >> H >> W >> N;
    map<Pii,int> area;
    repeat(i, N){
        int a,b;
        cin >> a >> b;
        repeat(k, 3){
            repeat(l, 3){
                int aa = a-k;
                int bb = b-l;
                if(aa <= 0 ||H < aa+2 ||bb <= 0 || W < bb+2)
                    continue;
                area[make_pair(aa, bb)]++;
            }
        }
    }
    ll sum[10];
    fill(sum,sum+10,0);
    sum[0]=(ll)(W-2)*(H-2);
    for(auto itr=area.begin();itr!=area.end();itr++){
        sum[itr->second]++;
        sum[0]--;
    }
    repeat(i, 10){
        cout << sum[i] << endl;
    }
    return 0;
}

