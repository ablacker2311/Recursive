#include<iostream>
#include<math.h>

int PageNumbering(int n){
     int count = 0;
    int m = n;
    int sum1 = 0;
    int sum2 = 0;
    while (m > 0){
        count++;
        m/=10;
    }

    for(int i = 1;i<=count-1;i++){
        sum1 += (pow(10,i) - pow(10,i-1))*i;
    }

    sum2 = count*(n-pow(10,count-1)+1);


    return sum1 + sum2;
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<PageNumbering(n);
}