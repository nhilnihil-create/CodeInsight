#include<iostream>
#include<string>
#include<vector>

void sort_dic(std::vector<std::string>& strings);
bool lt(std::string a, std::string b);
void swap(std::string& a, std::string& b);
int main()
{
    int N, L;
    std::vector<std::string> words;
    std::cin >> N >> L;
    words.resize(N);
    for(std::string& word : words){
        std::cin >> word;
    }
    sort_dic(words);
    std::string join = "";
    for(std::string s : words){
        join = join + s;
    }
    std::cout << join << '\n';
    return 0;
}
bool lt(std::string a, std::string b)
{
    int size = a.size();
    for(int i = 0; i < size; i++){
        if(a[i] < b[i]) return true;
        else if(b[i] < a[i]) return false;
    }
    return false;
}
void sort_dic(std::vector<std::string>& strings)
{
    int size = strings.size();
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(lt(strings[j], strings[i])) swap(strings[i], strings[j]);
        }
    }
}

void swap(std::string& a, std::string& b)
{
    std::string tmp = a;
    a = b;
    b = tmp;
}