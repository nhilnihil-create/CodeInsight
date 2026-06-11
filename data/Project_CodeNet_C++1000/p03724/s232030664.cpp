#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    map<long long, long long> T;

    for(long long i = 0; i < m; i++){
        long long a, b;
        cin >> a >> b;

        if(T.find(a) == T.end()){
            T[a] = 1;
        }
        else{
            T[a]++;
        }
        if(T.find(b) == T.end()){
            T[b] = 1;
        }
        else{
            T[b]++;
        }
    }

    map<long long, long long>::iterator it;

    for(it = T.begin(); it != T.end(); it++){
        if(it->second % 2 != 0){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}