#include <bits/stdc++.h>
using namespace std;

const int num_test = 10;            // Số test case
const int num_element = 1000000;    // Số phần tử mỗi test case

template<class T>
void heapify(T arr[], int n, int i){
    int largest = i;
    int _left = 2*i + 1, _right = 2*i + 2;
    
    if (_left < n && arr[_left] > arr[largest])         // Kiểm tra xem node hiện tại có lớn hơn hai node con ?
        largest = _left;
    if (_right < n && arr[_right] > arr[largest])
        largest = _right;

    if (largest != i){                  // Hoán đổi node hiện tại với node con nếu tồn tại node con có giá trị lớn hơn
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    } 
}

template<class T>
inline void HeapSort(T arr[], int n){
    for (int i=n/2 - 1;i >= 0;i-- )     // Khởi tạo cây Max-Heap với những nút không phải node lá
        heapify(arr, n, i);

    for (int i=n - 1;i > 0;i-- ){
        swap(arr[i], arr[0]);           // Chuyển phần tử lớn nhất trên cây Max-Heap về đúng thứ tự của nó
        heapify(arr, i, 0);             // Gọi hàm để duy trì tính chất của cây Max-Heap
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    ifstream input("../data/dataset.txt", ios::in);         // Mở file chứa bộ dữ liệu thử nghiệm
    ofstream output("../result/HeapSort.txt", ios::out);    // Mở file để ghi lại kết quả thử nghiệm
    output << fixed << setprecision(6);
    output << "HeapSort\n";

    for (int test = 1;test <= num_test;test++ ){
        float *arr = new float[num_element];           // Khởi tạo và đọc dữ liệu của từng test case
        float *check = new float[num_element];
        for (int i=0;i< num_element;i++ ){
            input >> arr[i];
            check[i] = arr[i];
        }

        auto begin_time = chrono::steady_clock::now();  // Bắt đầu ghi thời gian
        HeapSort(arr, num_element);
        auto end_time = chrono::steady_clock::now();    // Kết thúc ghi thời gian 
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