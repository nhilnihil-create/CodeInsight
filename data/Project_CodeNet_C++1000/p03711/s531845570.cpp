    #include<iostream>
    #include<set>
    using namespace std;
    int main(){
        set<int>s1,s2,s3;
        s1.insert(1);
        s1.insert(3);
        s1.insert(5);
        s1.insert(7);
        s1.insert(8);
        s1.insert(10);
        s1.insert(12);
        s2.insert(4);
        s2.insert(6);
        s2.insert(9);
        s2.insert(11);
        s3.insert(2);
        int x,y;
        cin>>x>>y;
        if(s1.find(x)!=s1.end()&&s1.find(y)!=s1.end()){
            cout<<"Yes"<<endl;
        }
        else
        if(s2.find(x)!=s2.end()&&s2.find(y)!=s2.end()){
            cout<<"Yes"<<endl;
        }
        else
        if(s3.find(x)!=s3.end()&&s3.find(y)!=s3.end()){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
     
    }