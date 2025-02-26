#include <bits/stdc++.h>
using namespace std;

const int num_test = 10;            // Số test case
const int num_element = 1000000;    // Số phần tử mỗi test case

template <class T>
inline void merge(T arr[], int _left, int mid, int _right){     // Trộn hai nửa dãy arr[_left...mid] và arr[mid+1..._right]
    int left_size = mid - _left + 1;            // Kích thước của dãy arr[_left...mid]
    int right_size = _right - mid;              // Kích thước của dãy arr[mid+1..._right]

    T *left_arr = new T[left_size];
    for (int i=0;i< left_size;i++ )
        left_arr[i] = arr[_left + i];

    T *right_arr = new T[right_size];
    for (int i=0;i< right_size;i++ )
        right_arr[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = _left;
    while (i < left_size && j < right_size){ 
        if (left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            i++, k++;
        }
        else{
            arr[k] = right_arr[j];
            j++, k++;
        }
    }

    while (i < left_size){
        arr[k] = left_arr[i];
        i++, k++;
    }

    while (j < right_size){
        arr[k] = right_arr[j];
        j++, k++;
    }
    
    delete[] left_arr;
    delete[] right_arr;
}

template <class T>
void MergeSort(T arr[], int _left, int _right){
    if (_left >= _right)    return;

    int mid = (_left + _right) >> 1;
    MergeSort(arr, _left, mid);             // Sắp xếp dãy arr[_left...mid]
    MergeSort(arr, mid + 1, _right);        // Sắp xếp dãy arr[mid+1..._right]
    merge(arr, _left, mid, _right);         // Trộn hai dãy arr[_left...mid] và arr[mid+1..._right] thành dãy arr[_left..._right] được sắp xếp tăng dần
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    ifstream input("../data/dataset.txt", ios::in);             // Mở file chứa bộ dữ liệu thử nghiệm
    ofstream output("../result/MergeSort.txt", ios::out);       // Mở file để ghi lại kết quả thử nghiệm
    output << fixed << setprecision(6);
    output << "MergeSort\n";

    for (int test = 1;test <= num_test;test++ ){
        float *arr = new float[num_element];        // Khởi tạo và đọc dữ liệu của từng test case
        float *check = new float[num_element];
        for (int i=0;i< num_element;i++ ){
            input >> arr[i];
            check[i] = arr[i];
        }

        auto begin_time = chrono::steady_clock::now();      // Bắt đầu ghi thời gian
        MergeSort(arr, 0, num_element - 1);
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