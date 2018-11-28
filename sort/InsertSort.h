//
// Created by mengjie on 11/27/18.
//

#ifndef SORT_INSERTSORT_H
#define SORT_INSERTSORT_H
void InsertSort(int a[], int length){
    /*
     * 插入排序
     * 从头开始保证走过的路有序,每加入一个元素就将其插入到正确的位置
     */
    int j,i;
    for(i=2;i<length;i++){
        if (a[i]<a[i-1]){
            a[0] = a[i];
            for(j=i-1;a[0]<a[j]; j--)
                a[j+1] = a[j];
            a[j+1] = a[0];
        }
    }
}
#endif //SORT_INSERTSORT_H
