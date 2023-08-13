#include<iostream>
#include<vector>
using ll = long long;

int main(){
    int n;
    std::cin>>n;
    std::vector<int> v(n);
    for(int i = 0;i<v.size();i++){
        std::cin>>v[i];
    }
    for(int x:v){
        std::cout<<x<<" "; //2 3 1 5 4
    }
    v.insert(v.begin()+2,100); // chèn thêm phần tử 100 vào vị trí thứ 2
        //2 3 100 1 5 4
    std::cout<<'\n';
    for(int x:v){
        std::cout<<x<<" "; //2 3 1 5 4
    }
}