#include <iostream>
#include <string>

std::string getInitial(std::string word);
 
int main() {
    std::string firstWord;
    std::string secondWord;
    std::string thirdWord;
    std::cin >> firstWord >> secondWord >> thirdWord;
    
    std::string abbreviation = getInitial(firstWord) + getInitial(secondWord) + getInitial(thirdWord);
    
    std::cout << abbreviation << std::endl;    
}

std::string getInitial(std::string word) {
    return std::string {word.at(0)};
}