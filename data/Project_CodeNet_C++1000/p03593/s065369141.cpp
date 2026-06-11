#include<bits/stdc++.h>
int main(){
    int h,w;std::cin>>h>>w;
    std::vector<int>a(26);
    for(int i=0;i<h*w;i++){
        char c;std::cin>>c;
        a.at(c-'a')++;
    }
    int two=0,one=0;
    for(int x:a){
        if(x%4)two++;
        if(x%2)one++;
    }
    int two_max=((h%2)*w+(w%2)*h)/2;
    std::cout<<(one<=1
            &&two<=two_max
            ?"Yes":"No")<<'\n';
}

