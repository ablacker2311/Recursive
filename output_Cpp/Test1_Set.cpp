#define MAX 100001
#include<iostream>
#include<set>


int main(){
    int arr[MAX];
    int n;
    std::cin>>n;

    std::set<int> se; //khởi tạo set

    for(int i = 0;i < n; i++){
        std::cin>>arr[i];
        se.insert(arr[i]);
    }
	std::cout<<se.size()<<" ";
}
