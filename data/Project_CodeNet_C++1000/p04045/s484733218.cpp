/// Source : https://atcoder.jp/contests/abc042/tasks/arc058_a
/// Author : liuyubobobo
/// Time   : 2020-09-22

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(10*N*logN)
/// Space Complexity: O(1)
class Solution{

public:
    int handMoney(int N, const vector<bool>& dislikes){

        int smallestlike = 0;
        for(;dislikes[smallestlike];smallestlike ++);

        vector<int> num;
        while(N) num.push_back(N % 10), N /= 10;

        int carry = 0;
        for(int i = 0; i < num.size(); i ++){
            int d = num[i] + carry;
            for(; d < 10; d ++)
                if(!dislikes[d]) break;

            if(d != 10){
                if(d > num[i]) for(int j = 0; j < i; j ++) num[j] = smallestlike;
                num[i] = d, carry = 0;
            }
            else{
//                for(int j = 0; j < i; j ++) num[j] = smallestlike;
                num[i] = smallestlike, carry = 1;
            }
        }
        if(carry){
            for(int i = 1; i < 10; i ++)
                if(!dislikes[i]){
                    num.push_back(i);
                    break;
                }
        }

        int res = 0;
        for(int i = num.size() - 1; i >= 0; i --)
            res = res * 10 + num[i];
        return res;
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
