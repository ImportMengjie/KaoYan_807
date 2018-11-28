//
// Created by mengjie on 11/28/18.
//

#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H

void AdjustDown(int a[], int k, int len){
    a[0] = a[k];
    for (int i=k*2; i<=len; i*=2){
        if(i<len&&a[i]<a[i+1])
            i++;
        if(a[0]>=a[i])
            break;
        else{
            a[k] = a[i];
            k=i;
        }
    }
    a[k] = a[0];
}

void HeapSort(int a[], int length){
    // build max heap
    for (int i=length/2; i>0; i--)
        AdjustDown(a, i, length);

    for (int i=length;i>1; i--){
        int t=a[1];
        a[1] = a[i];
        a[i] = t;

        AdjustDown(a,1, i-1);
    }
}

#endif //SORT_HEAPSORT_H
