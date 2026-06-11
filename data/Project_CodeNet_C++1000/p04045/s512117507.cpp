#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


class Solution{

public:
    int handMoney(int N, const vector<bool>& dislikes){

        int money = N;
        while(!ok(money, dislikes)) money ++;
        return money;
    }

private:
    bool ok(int money, const vector<bool>& dislikes){

        while(money){
            if(dislikes[money % 10]) return false;
            money /= 10;
        }
        return true;
    }
};

int main() {

    int N, K;
    scanf("%d%d", &N, &K);

    vector<bool> dislikes(10, false);
    for(int i = 0; i < K; i ++){
        int x; scanf("%d", &x);
        dislikes[x] = true;
    }

    printf("%d\n", Solution().handMoney(N, dislikes));

    return 0;
}
