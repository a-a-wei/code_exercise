# include <bits/stdc++.h>
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        random_shuffle(nums.begin(),nums.end());
        quickSort(nums,0,nums.size()-1);
        return nums;
    }

    void quickSort(vector<int>&arr,int beg,int end){
        if(beg >= end) return;
        int lt = beg, gt = end;
        //三路快排
        /* 小于pv :  [beg, lt-1]
           等于pv ： [lt, gt]， 运行时为[lt, i-1]
           大于pv ： [gt+1, end]
        */
        int pv = arr[beg];
        for(int i=beg;i<=gt;i++){
        // [beg,lt-1],[lt, i-1], [gt+1, end] 都是已经遍历的
            if(arr[i] < pv){
        //如果小于pv，将它与小于区间和等于区间的边界lt(不属于小于,属于等于)交换，
        //此时小于区间为[beg,lt], 等于区间为[lt+1,i],更新边界使满足定义
                swap(arr[lt],arr[i]);
                lt++;
            }else if(arr[i] > pv){
        //如果大于pv，将它与大于区间的边界gt(不属于大于)交换，
        //此时大于区间为[gt,end], 等于区间为[lt,i-1],更新边界使满足定义
                swap(arr[gt],arr[i]);
                gt--;
                //此时的i是未访问的部分
                i--;
            }
        }
        quickSort(arr,beg,lt-1);
        quickSort(arr,gt+1,end);
    }

};