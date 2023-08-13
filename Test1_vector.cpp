#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; // số thao tác
    std::cin>>n;
    vector <int> v;

    for(auto i = 0;i<n;i++){
        int tt;std::cin>>tt;
        if(tt == 1){
            int value;
            std::cin>>value;
            v.push_back(value);
        }
        else if(tt == 2 && !v.empty()){
            v.pop_back();
        }
    }

    if(v.empty())
        std::cout<<"EMPTY\n";
    else{
        for(auto x:v){
            std::cout<<x<<" ";
        }
    }
}