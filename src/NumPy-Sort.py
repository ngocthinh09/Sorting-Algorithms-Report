import numpy as np
from time import time

num_test = 10       # Số test case

file = open("../data/dataset.txt", "r")                     # Mở file để đọc bộ dữ liệu thử nghiệm
with open("../result/NumPy-Sort.txt", "w") as result:       # Mở file để ghi lại kết quả thử nghiệm
    result.write('Sort function in NumPy library\n')
    for test in range(num_test):
        arr = np.array(list(map(np.float64, file.readline().split())))          # Đọc dữ liệu
        
        begin_time = time()     # Bắt đầu tính thời gian
        arr.sort()
        end_time = time()       # Kết thúc tính thời gian
        
        runtime = (end_time - begin_time)*1000      # Thời gian hàm sort() của NumPy chạy
        result.write(f'Runtime on test {test + 1} : {runtime:.6f} ms\n') 
file.close()