import matplotlib.pyplot as plt
import numpy as np
 
QuickSort = [51.0079, 55.9493, 233.7600, 223.7761, 220.3409, 207.5132, 229.1986, 229.1046, 215.3259, 226.8917]  
HeapSort = [394.6715, 403.1879, 498.5841, 539.5935, 537.9123, 536.1245, 485.9410, 531.7836, 497.2424, 491.6734]  
MergeSort = [401.6811, 423.2230, 454.2369, 463.1989, 473.5682, 447.3024, 444.6395, 443.1467, 456.2742, 442.3780]  
Sort_STL = [100.2345, 84.1964, 266.6615, 236.4386, 254.5048, 264.6411, 245.5647, 249.7425, 231.7402, 256.0558]  
Sort_NumPy = [32.0603, 18.5780, 21.7027, 19.7443, 17.9102, 25.8657, 17.6632, 18.1915, 19.7801, 18.1293]  
runtime = [QuickSort, HeapSort, MergeSort, Sort_STL, Sort_NumPy]
category = ["QuickSort", "HeapSort", "MergeSort", "Sort (C++)", "Sort (NumPy)"]

colors = ['#0072B2', '#D55E00', '#009E73', '#F0E442', '#CC79A7']

x = np.arange(len(category))
bar_width = 0.15

(figure, axes) = plt.subplots(2, 1, figsize = (14, 11))
plt.rc('font', family = 'Times New Roman', size = 13)
plt.suptitle("Kết quả thử nghiệm trên bộ dữ liệu", fontsize = 20, fontweight = 'bold')

for row in range(2):
    ax = axes[row]
    (start, end) = (0, 5) if (row == 0) else (5, 10)
    for i in range(len(category)):
        bars = ax.bar(x + i*bar_width, runtime[i][start:end:], bar_width, label = category[i], color = colors[i])
        for bar in bars:
            height = bar.get_height()
            ax.text(bar.get_x() + bar_width/2, height, f"{height:.1f}", ha = "center", va = "bottom", fontsize = 10)
        
    label = [f"Dãy {i + 1}" for i in range(start,end)]
    ax.set_xticks(x + bar_width*2)
    ax.set_xticklabels(label, fontsize = 12)
    ax.set_ylabel("Thời gian thực hiện (ms)", fontsize = 13)
    ax.legend(fontsize = 8)

plt.savefig("img/bar-chart-runtime.png", dpi = 300, bbox_inches='tight')
plt.show()