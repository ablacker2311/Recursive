#include<iostream>
#include<math.h>
using namespace std;

bool arr[1000001];

void snt(int n){
    for (int i = 2; i <= n; i++)
        arr[i] = true;
    arr[0] = arr[1] = false;
    for (int i = 2; i <= sqrt(n); i++)
    if (arr[i])
        for (int j = i * i; j <= n; j += i)
            arr[j] = false;
}

int greatestCommonPrimeDivisor(int a, int b)
{  
    snt(min(a,b));

    for(int i= min(a,b);i >= 2;i--){
        if(arr[i] && a%i == 0 && b%i == 0)
            return i;
    }

    return -1;

}

int main(){
    int a;int b;
    cin>>a>>b;
    cout<<"So nguyen to lon nhat ma la uoc chung cua a va b la:"<<greatestCommonPrimeDivisor(a,b);

}