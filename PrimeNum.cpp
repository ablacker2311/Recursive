#include<iostream>
#include<math.h>
bool arr[100001];
void snt(int n){
    for(int i = 2;i<=n;i++)
        arr[i] = true;
    arr[0] = arr[1] = false;
    for(int i = 2;i<=sqrt(n);i++){
        if(arr[i]){
            for(int j = 2*i;j<=n;j+=i)
                arr[j] = false;
        }
    }
}

int primeSum(int n){
    int sum = 0;
    for(int i = 0;i<=n;i++){
        if(arr[i])
            sum+=i;
    }
    return sum%22082018;
}
int main(){
    int n;
    std::cin>>n;
    snt(n);
    std::cout<<primeSum(n);
}

