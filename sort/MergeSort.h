//
// Created by mengjie on 11/28/18.
//

#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

void merge(int a[], int low, int mid, int high, int b[]){
    for(int i=low; i<=high; i++)
        b[i] = a[i];
    int l,h,k;
    for (k=low,l=low,h=mid+1; l<=mid&&h<=high;k++){
        if(b[l]<=b[h])
            a[k] = b[l++];
        else
            a[k] = b[h++];
    }
    while(l<=mid)
        a[k++]=b[l++];
    while(h<=high)
        a[k++]=b[h++];
}

void MergeSort(int a[], int low, int high, int b[]){
    if (low<high){
        int mid = (low+high)/2;
        MergeSort(a, low, mid,b);
        MergeSort(a,mid+1, high, b);
        merge(a, low, mid , high, b);
    }
}

void MergeSort(int a[], int len){
    int *b = new int[len];
    MergeSort(a, 1, len, b);
    delete []b;
}

#endif //SORT_MERGESORT_H
