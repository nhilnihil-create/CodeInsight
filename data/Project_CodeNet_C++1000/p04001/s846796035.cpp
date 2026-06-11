#include <iostream>
#include <string>
 
using namespace std;
 
long add(const string& numbers, const int bitsOfPlusPosition);
 
int main() {
    string numbers;
    cin >> numbers;
    
    long answer = 0;
    for (int bits = 0; bits < (1 << (numbers.size() - 1)); ++bits) {
        answer += add(numbers, bits);
    }
    cout << answer << endl;       
}
 
long add(const string& numbers, const int bitsOfPlusPosition) {
    const int DECIMAL_BASE = 10;
    long sum = 0;
    long term = 0;
    for (size_t i = 0U; i < numbers.size(); ++i) {
        term *= DECIMAL_BASE;
        term += numbers.at(i) - '0';
        if (bitsOfPlusPosition & (1 << i) || i == numbers.size() - 1) {
            sum += term;
            term = 0;
        }
    }
    return sum;
}