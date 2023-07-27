/*Cho số tự nhiên product
Hãy tìm số nguyên dương nhỏ nhất (lớn hơn 0) 
mà tích các chữ số của số đó bằng product. 
Nếu không có số thỏa mãn, trả ra -1.*/

#include<iostream>



int solve(int product){
    if(product == 0)
        return 10;
    if(product == 1)
        return 1;
    
    int ans = 0;
    for(int i = 9;i >= 2;i--){
        while(product%i == 0){
            ans = ans*10 + i;
            product /=i;
        }
    }

    int ans2 = 0;
    while(ans != 0)
        {ans2 = ans2*10 + ans%10;
        ans/=10;
        }

        return (product == 1) ? ans2 : -1;
}
int main(){
    int product;
    std::cin>>product;
    std::cout<<solve(product);
}

