import numpy as np

size = 1000000              # Số phần tử của mỗi dãy
num_test = 10               # Số test case 

with open('../data/dataset.txt', "w") as file:
    for test in range(num_test):   
        if (test == 0):
            random_numbers = np.random.uniform(-1e9, 1e9, size)   
            random_numbers = np.sort(random_numbers)                # Tạo mảng sắp xếp tăng dần 
        elif (test == 1):
            random_numbers = np.random.uniform(-1e9, 1e9, size)   
            random_numbers = np.sort(random_numbers)[::-1]          # Tạo mảng sắp xếp giảm dần
        else:
            random_numbers = np.random.uniform(-1e9, 1e9, size)   # Tạo mảng ngẫu nhiên
            
        for number in random_numbers:
            file.write(f'{number} ') 
        file.write('\n')