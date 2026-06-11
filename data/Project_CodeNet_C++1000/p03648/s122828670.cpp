#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long K;
    cin >> K;
    cout << 50 << endl;
    long nums[50];
    for(int i = 0; i < 50; i++){
        nums[i] = K / 50 + 49;
    }
    for(int i = 0; i < K % 50; i++){
        nums[i] += 51;
        for(int j = 0; j < 50; j++){
            nums[j]--;
        }
    }
    string ans_string = "";
    for(int i = 0; i < 50; i++){
        ans_string += to_string(nums[i]) + " ";
    }
    ans_string.pop_back();
    cout << ans_string << endl;
}

