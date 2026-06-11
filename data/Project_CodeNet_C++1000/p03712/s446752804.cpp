#include <iostream>
#include <string>
#include <vector>

void addFrame(int heightPixel, int widthPixel, std::vector<std::string>& picture);

int main() {
    int heightPixel = 0;
    int widthPixel = 0;
    std::cin >> heightPixel >> widthPixel;
    
    std::vector<std::string> picture;
    std::string line;
    for (int i = 0; i < heightPixel; ++i) {
        std::cin >> line;
        picture.push_back(line);
    }
    
    addFrame(heightPixel, widthPixel, picture);
    
    for (std::string line : picture) {
        std::cout << line << std::endl;
    }
}

void addFrame(int heightPixel, int widthPixel, std::vector<std::string>& picture) { 
    for (int i = 0; i < heightPixel; ++i) {
        picture.at(i) = "#" + picture.at(i) + "#";
    }
    
    std::string frame;
    for (int i = 0; i < widthPixel + 2; ++i) {
        frame += "#";
    }
        
    picture.insert(picture.begin(), frame);
    picture.push_back(frame);
}