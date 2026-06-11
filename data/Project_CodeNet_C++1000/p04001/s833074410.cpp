#include <iostream>
#include <string>
 
using namespace std;
 
long long addition(const string& numbers, const int& positionOfPlus);
 
int main() {
    string numbers;
    cin >> numbers;
    
    //longでいい
    long long answer = 0;
    //bitじゃなくてbits
    for (int bit = 0; bit < (1 << (numbers.size() - 1)); ++bit) {
        answer += addition(numbers, bit);
    }
    cout << answer << endl;       
}

//関数名が名詞になっているadd?
//positionOfPlusは使い方と名前が乖離している
//+の位置はboolの配列でもできそう
long long addition(const string& numbers, const int& positionOfPlus) {
    long long sum = 0;
    long long term = 0;
    //0Uで表記
    for (size_t i = 0; i < numbers.size(); ++i) {
        //10がマジックナンバーっぽい
        term *= 10;
        term += numbers.at(i) - '0';
        if (positionOfPlus & (1 << i) || i == numbers.size() - 1) {
            sum += term;
            term = 0;
        }
    }
    return sum;
}
