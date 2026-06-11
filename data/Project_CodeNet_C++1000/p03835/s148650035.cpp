#include<iostream>

int main()
{
    int k,s,x,y,z,ans=0;
    std::cin>>k>>s;
    for(x=0;x<=k;x++){
        for(y=0;y<=k;y++){
            for(z=0;z<=k;z++){
                if(x+y+z==s)ans++;
            }
        }
    }
    std::cout<<ans<<std::endl;
}
