    #include<iostream>
    #include<string>
     
    using namespace std;
     
    int main()
    {
        string a, b, c;
        cin>>a>>b>>c;
        a[0] -= 32;
        b[0] -= 32;
        c[0] -= 32;
        cout<<a[0]<<b[0]<<c[0]<<endl;
        return 0;
    }