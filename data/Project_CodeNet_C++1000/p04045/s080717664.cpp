#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

template<typename T>
std::ostream & operator<<(std::ostream & os, std::vector<T> vec)
{
    os<<"{ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, " "));
    os<<"}";
    return os;
}

std::vector <int> get_digits(int num){
    std::set <int> digits;
    while(num){
        digits.insert(num % 10);
        num /= 10;
    }
    return std::vector<int>(digits.begin(), digits.end());
}

int construct(int payable_amount, const std::vector <int> &allowable_digits){
    int answer = -1;
    for(int i = payable_amount ; ; ++i){
        std::vector <int> digits = get_digits(i);
        //std::cout << i << " " << digits << '\n';
        if(std::includes(allowable_digits.begin(), allowable_digits.end(), digits.begin(), digits.end())){
            answer = i;
            break;
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    int N,K;
    std::cin >> N >> K;
    
    std::vector <int> allowable_digits;
    allowable_digits.reserve(10 - K);
    
    int start = 0;

    for(int i = 0 ; i < K ; ++i){
        int disliked_digit;
        std::cin >> disliked_digit;
        for(int j = start ; j < disliked_digit ; ++j){
            allowable_digits.emplace_back(j);
        }
        start = disliked_digit + 1;
    }
    
    for(int i = start ; i < 10 ; ++i){
        allowable_digits.emplace_back(i);
    }

    // "allowable_digits" is already sorted as the disallowable digits were given in sorted order
    std::cout << construct(N, allowable_digits) << '\n';

    return 0;
}
