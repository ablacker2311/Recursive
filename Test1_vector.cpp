#include<iostream>
#include<vector>
#include<set>
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

pair<int,int> p = make_pair(10,20); // tạo một biến p có kiểu dự liệu pair với phần tử đầu tiên là 10, phần tử thứ 2 là 20
pair<int,int> p = {10,20};  // tạo một biến p có kiểu dự liệu pair với phần tử đầu tiên là 10, phần tử thứ 2 là 20
std::cout<<p.first<<" "<<p.second<<" "; // in ra phần tử đầu tiên và phần tử thứ 2

}
