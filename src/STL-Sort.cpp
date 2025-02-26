#include <bits/stdc++.h>
using namespace std;

const int num_test = 10;
const int num_element = 1000000;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    ifstream input("../data/dataset.txt", ios::in);         // Mở file chứa bộ dữ liệu thử nghiệm
    ofstream output("../result/STL-Sort.txt", ios::out);    // Mở file để ghi lại kết quả thử nghiệm
    output << fixed << setprecision(6);
    output << "STL-Sort\n";

    for (int test = 1;test <= num_test;test++ ){
        float *arr = new float[num_element];        // Khởi tạo và đọc dữ liệu của từng test case
        for (int i=0;i< num_element;i++ )
            input >> arr[i];

        auto begin_time = chrono::steady_clock::now();      // Bắt đầu ghi thời gian
        sort(arr, arr + num_element);
        auto end_time = chrono::steady_clock::now();        // Kết thúc ghi thời gian
        chrono::duration<double, milli> duration = end_time - begin_time;   // Tính thời gian chạy với độ chính xác milli giây
        output << "Runtime on test " << test << ": " << (double)duration.count() << " ms. \n";
         
        delete[] arr;
    }

    input.close();
    output.close();
}