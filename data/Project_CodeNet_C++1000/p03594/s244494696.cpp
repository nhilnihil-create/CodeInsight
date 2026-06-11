#include<bits/stdc++.h>
int main(){
    std::string s="RYGB";
    int h,w,d;std::cin>>h>>w>>d;
    if(d&1){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                std::cout<<s[(i+j)%2];
            }
            std::cout<<'\n';
        }
    }else{
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int x=(i+j)/2,y=(i+w-1-j)/2;
                std::cout<<s.at(1*((x%d)/(d/2))+2*((y%d)/(d/2)));
            }
            std::cout<<'\n';
        }
    }
}
