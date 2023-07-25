// Hải vừa được trúng thưởng cực lớn trong một trò chơi. Ban tổ chức đã chuẩn bị sẵn cho Hải n món quà có giá trị lần lượt là a0, a1, ..., an-1.

// Ban tổ chức cho phép Hải chọn quà theo luật như sau:

// Mỗi lượt chỉ được chọn 1 món quà.
// Nếu lượt này đã chọn món quà thứ k thì lượt sau chỉ được chọn các phần quà từ k + 1 đến n - 1.
// Ở lượt chọn quà lẻ (lượt 1, lượt 3,...) thì Hải được chọn bất kỳ phần quà giá trị tùy ý.
// Ở lượt chọn quà chẵn (lượt 2, lượt 4,..) thì Hải bắt buộc phải chọn phần quà có cùng giá trị với phần quà ngay trước đó mà Hải đã chọn.
// Hãy tìm và in ra tổng giá trị lớn nhất của các phần quà mà Hải có thể chọn.




#define MAX 100001
#include<iostream>

int arr[MAX];
int check[MAX][2] ;


int solve(int arr[],int n){
    for(int i = 1; i < n; i++)
    {

        for(int j = 0; j < i; ++j)
            if(arr[i] == arr[j] )
                check[i][1] = std::max(check[j][0] + arr[i],check[i][1]);
        
        for(int j = 0;j < i; ++j)
            check[i][0] = std::max(check[j][1] + arr[i],check[i][0]);
    }
    int max = -1;
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < 2; j++)
	        if (check[i][j] > max)
                max = check[i][j];
    
    return max;
}

int main(){
    int n;
    std::cout<<"nhap so luong mon qua:";
    std::cin>>n;

    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
     for(int i = 0;i < n;i++){
        check[i][0] = arr[i];
        check[i][1] = 0;
    }

    std::cout<<solve(arr,n);

}