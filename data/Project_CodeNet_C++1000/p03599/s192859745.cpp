#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(){
    long long A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    map<pair<long long, long long>, long double> T;
 
    for(long long a = 0; a < 31; a++){
        for(long long b = 0; b < 31; b++){
            for(long long c = 0; c < 101; c++){
                for(long long d = 0; d < 101; d++){
                    long long water = 100*A*a + 100*B*b;
                    long long sugar = C*c + D*d;
                    if(water == 0) continue;
                    if(water + sugar > F) continue;
                    if(water * E < sugar*100) continue;

                    T[make_pair(water, sugar)] = (long double)sugar/((long double)water+(long double)sugar);
                }
            }
        }
    }

    long double maxv = 0;

    map<pair<long long, long long>, long double>::iterator it;

    for(it = T.begin(); it  != T.end(); it++){
        if(maxv < it->second) maxv = it->second;
    }

    //printf("maxv %Lf\n", maxv);
    long long W = 0, S = 0;
    for(it = T.begin(); it  != T.end(); it++){
        if(maxv == it->second) W = it->first.first, S = it->first.second;
    }

    cout << W + S << " " <<  S << endl;
    return 0;
}
