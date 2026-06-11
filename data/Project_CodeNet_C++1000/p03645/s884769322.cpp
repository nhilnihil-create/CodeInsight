#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;


long long n, m;

int main(){
    cin >> n >> m;
    

    set<long long> from_1;
    set<long long> from_n;

    for(int i = 1;i <= m; i++){
        long long a, b;
        cin >> a >> b;
        if(a == 1){
            from_1.insert(b);
        }
        if(b == n){
            from_n.insert(a);
        }    
    }

    if(from_n.empty()){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    if(m == 1){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    bool flag = false;

    set<long long>::iterator it;

    for(it = from_1.begin(); it != from_1.end(); it++){
        if(from_n.find(*it) != from_n.end()){
            flag = true;
            break;
        }
    }

    if(flag == true){
        printf("POSSIBLE\n");
    }
    else{
        printf("IMPOSSIBLE\n");
    }
    
    return 0;

}