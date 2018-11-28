#include <iostream>
#include "InsertSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "MergeSort.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    int a[] = {-1, 3,4,2,1,8,9,7,0,6,5};
    for (int i=0; i<11; i++)
        printf("%d\t",a[i]);
//    InsertSort(a, 11);
//    QuickSort(a,0,11);
//    HeapSort(a, 10);
    MergeSort(a, 10);


    printf("\n");
    for (int i=0; i<11; i++)
        printf("%d\t",a[i]);



    return 0;
}