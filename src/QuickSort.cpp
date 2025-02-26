#include <bits/stdc++.h>
using namespace std;

const int num_test = 10;                // Số test case
const int num_element = 1000000;        // Số phần tử mỗi test case 

template<class T>
void QuickSort(T arr[], int _left,int _right){
    if (_left >= _right)    return;

    int mid = (_left + _right) >> 1;
    T pivot = arr[mid];                 // Chọn phần tử ở vị trí mid làm pivot

    int i = _left, j = _right;
    while (i < j){                      // Hoán đổi vị trí các phần tử lớn hơn pivot và nằm bên trái pivot
        while (arr[i] < pivot)  i++;    //                             nhỏ hơn pivot và nằm bên phải pivot
        while (arr[j] > pivot)  j--;

        if (i <= j){
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }

    // Tiếp tục đệ quy và sắp xếp các dãy có kích thước nhỏ hơn
    if (_left < j)
        QuickSort(arr, _left, j);
    if (i < _right)
        QuickSort(arr, i, _right);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    ifstream input("../data/dataset.txt", ios::in);             // Mở file chứa bộ dữ liệu thử nghiệm
    ofstream output("../result/QuickSort.txt", ios::out);       // Mở file để ghi lại kết quả thử nghiệm
    output << fixed << setprecision(6);
    output << "QuickSort\n";

    for (int test = 1;test <= num_test;test++ ){
        float *arr = new float[num_element];        // Khởi tạo và đọc dữ liệu của từng test case
        float *check = new float[num_element];
        for (int i=0;i< num_element;i++ ){
            input >> arr[i];
            check[i] = arr[i];
        }

        auto begin_time = chrono::steady_clock::now();      // Bắt đầu ghi thời gian
        QuickSort(arr, 0, num_element - 1);
        auto end_time = chrono::steady_clock::now();        // Kết thúc ghi thời gian 
        chrono::duration<double, milli> duration = end_time - begin_time;   // Tính thời gian chạy với độ chính xác milli giây 
        output << "Runtime on test " << test << ": " << (double)duration.count() << " ms. ";
        
        sort(check, check + num_element);
        bool flag = true;
        for (int i=0;i < num_element;i++ )      // Kiểm tra tính đúng đắn của hàm QuickSort
            if (arr[i] != check[i])
                flag = false;
        output << "Double-check by std::sort on test " << test << ": " << (flag ? "True" : "False") << '\n';
        
        delete[] arr;
        delete[] check;
    }

    input.close();
    output.close();
}