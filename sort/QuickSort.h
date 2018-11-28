//
// Created by mengjie on 11/27/18.
//

#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H

int partition(int a[],int low,int high){
    int pivot = a[low];
    while(low<high){
        while(a[high]>=pivot && low<high)
            high--;
        a[low] = a[high];
        while(a[low]<=pivot && low<high)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void QuickSort(int a[], int low, int high){
    if (low<high){
        int mid = partition(a, low,high);
        QuickSort(a, low, mid-1);
        QuickSort(a, mid+1, high);
    }
}



#endif //SORT_QUICKSORT_H
