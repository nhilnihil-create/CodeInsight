#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;


    long long sum = 0;
    vector<long long> point;
    for (long long i = 1; i <= n; ++i){
        sum += i;
        point.push_back(i);
        if (sum > n){
            long long remove_i = sum - n;
            point.erase(point.begin() + remove_i - 1 );
            break;
        }else if (sum == n){
            break;
        }
    }

    for (const auto& v : point) {
        cout << v << endl;
    }

}