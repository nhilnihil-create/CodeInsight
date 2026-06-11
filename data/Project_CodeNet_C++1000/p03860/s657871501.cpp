#include <iostream>
#include <string>
#include <vector>

char getInitial(const std::string& word);
 
int main() {
    std::vector<std::string> words;
    std::string word;
    while(std::cin >> word) {
        words.push_back(word);
    }
    
    std::string abbreviation;
    for(std::string word : words) {
        abbreviation += getInitial(word);
    }
    
    std::cout << abbreviation << std::endl;
}

char getInitial(const std::string& word) {
    return word.at(0);
}
