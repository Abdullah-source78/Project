#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout<<"Enter Numbers for Swap :";
    cin>>a>>b;
    
    cout <<"Values before swap are :"<<endl<<"  a = "<<a<<"  b = "<<b<<" "<<endl;
    int temp = a ;
    a = b;
    b=temp;
    cout <<"Values after swap are :"<<endl<<"  a = "<<a<<"  b = "<<b<<endl;
    return 0;
}