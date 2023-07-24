#define MAX 100001
#include<iostream>

int main(){
    int arr[MAX];
    int l[MAX];
    
    int n;
    std::cout<<"input n:";
    std::cin>>n;

    for(int i = 0;i<n;i++){
        std::cout<<"input value of money:";
        std::cin>>arr[i];
    }

    int x;
    std::cout<<"input money want to withdraw :";
    std::cin>>x;

    for(int i=1;i<= x;i++){
        l[i] = INT_MAX;
    }

    l[0] = 0;

    for( int i = 1;i <= x;i++)
        for(int j = 0;j<n;j++)
            if(i >= arr[j])
                l[i] = std::min(l[i],l[i-arr[j]]+1);

    if(l[x] > 0)
        std::cout<<l[x];
    else std::cout<<0;

}