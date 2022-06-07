//
// Created by rain on 2022/5/26.
//

#ifndef ALG_ALG_H
#define ALG_ALG_H
#include<vector>
#include <iostream>
/*
 *Josephus问题是由古罗马著名史学家Josephus所提出的问题演变而来的。Josephus问题的
 * 提法很多，如“猴子选大王问题”、“旅行社奖游客问题”等，就其数学本质而言是相同的问题。Josephus问题的一般描述为：设有n个人围坐一圈并由1到n编号。从某个人（例如编
 * 号为k的人）开始报数，数到m的人出列；接着从出列的下一个人开始重新1到m报数，数到m的人又出列；如此反复地报数和出列，直到最后一个人出
 * 列为止。要求设计确定这n个人出列序列的程序。
 *
 *
 * */
void alg3(){
    using namespace std;
    vector<int> arr;
    cout<<"一共多少人？:"<<endl;
    int n;
    cin>> n;
    for (int i = 1; i <= n ; ++i) {
        arr.push_back(i);
    }
    int m;
    int k;
    cout<<"从谁开始报数？"<<endl;
    cin>>k;
    cout<<"数到几？"<<endl;
    cin>>m;
    int index=k-1 ;
    int j=arr.size();
    for (int i = 0; i < j ; ++i) {
            index=  (index + m-1) % n ;
            cout<<arr[index]<<" ";
            arr.erase(arr.begin()+index);
            n--;
    }
}
void jo1(){
    using namespace std;

    vector<int> arr;
    cout<<"一共多少人？:"<<endl;
    int n;
    cin>> n;
    for (int i = 1; i <= n ; ++i) {
        arr.push_back(i);
    }

    const int N=10001;
    int m;
    int k;
    cout<<"从谁开始报数？"<<endl;
    cin>>k;
    cout<<"数到几？"<<endl;
    cin>>m;
    int m_;
    bool isOuted[N]={false };
    int index=-1 ;
    for (int i = 0; i < arr.size(); ++i) {
        m_=m;
        while (m_--){
            index++;
            index = index % n;
            while (isOuted[index]== true){
                index++;
                index = index % n;
            }
        }
        cout<<arr[index]<<" ";
        isOuted[index]= true;
    }
}
void solov(){
    const int N=1000;
    using namespace std;
    int n ;
    int k;
    cin>> n;

    cin>>k;
    int a_i[k];
    std::vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        v.push_back(i+1);
    }
    for (int i = 0; i < k; ++i) {
        cin>>a_i[i];
    }
    int index=0;
    for (int i = 0; i < k; ++i) {
        index =  (index + a_i[i]) % n;
        std::cout<<v[index]<<" ";
        v.erase(v.begin()+index);
        n--;
    }


}
void jo(){
    using namespace std;

    vector<int> arr;
    cout<<"一共多少人？:"<<endl;
    int n;
    cin>> n;
    for (int i = 1; i <= n ; ++i) {
        arr.push_back(i);
    }

    const int N=10001;
    int m;
    int k;
    cout<<"从谁开始报数？"<<endl;
    cin>>k;
    cout<<"数到几？"<<endl;
    cin>>m;
    int m_;
    bool isOuted[N]={false };
    int index=((k-1+m) % n)-1 ;
    for (int i = 0; i < arr.size(); ++i) {
        m_=m;
        cout<<arr[index]<<" ";
        isOuted[index]= true;
        if(std::count(isOuted,
                      isOuted+n,
                      false)!=0){
            while (m_--){
                index++;
                index=index%n;
                while (isOuted[index]== true){
                    index++;
                    index=index% n;
                }
            }
        }
    }
}


/*
 *
 * n 个小朋友围成一圈，玩数数游戏。

小朋友们按顺时针顺序，依次编号为 1∼n。

初始时，1 号小朋友被指定为领头人。

游戏一共会行进 k 轮。

在第 i 轮中，领头人会从他的顺时针方向的下一个人开始，按顺时针顺序数 ai 个人。

其中，最后一个被领头人数到的人被淘汰出局，这也意味着该轮游戏结束。

出局者的顺时针方向的下一个人被指定为新领头人，引领新一轮游戏。

例如，假设当游戏即将开始第 i 轮时，还剩下 5 个小朋友，编号按顺时针顺序依次为 8,10,13,14,16，
 并且当前领头人为 13 号小朋友，ai=12，则第 i 轮游戏结束后，最后一个被数到的小朋友为 16 号小朋友，
 他将被淘汰出局，并且处于其下一位的第 8 号小朋友将被指定为新领头人。

现在，请你求出每一轮次被淘汰的小朋友的编号。

输入格式
第一行包含两个整数 n,k。

第二行包含 k 个整数 a1,a2,…,ak。

输出格式
一行，k 个整数，其中第 i 个整数表示在第 i 轮中被淘汰的小朋友的编号。

数据范围
前三个测试点满足 2≤n≤10。
所有测试点满足 2≤n≤100，1≤k≤n−1，1≤ai≤109。
 * */

void alg2(){
    const int N=1000;
    using namespace std;
    int n ;
    int k;
    cin>> n;
    std::vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        v[i]=i+1;
    }
    cin>>k;
    int a_i[k];
    for (int i = 0; i < k; ++i) {
        cin>>a_i[i];
    }
    bool isOuted[N]={false};
    int index=0;
    for (int i = 0; i < k; ++i) {
        while (a_i[i]--){
            index++;
            index =index%n;
            while(isOuted[index]== true){
                index++;
                index =index%n;
            }
        }
        cout<<v[index]<<" ";
        isOuted[index]= true;
        index++;
        index =index%n;
        while(isOuted[index]== true){
            index++;
            index =index%n;
        }
    }

}

//## sort
;
void printArr(int* arr,int n){
    using namespace std;
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insertSort(int* arr,int n){
    int e=0;
    int j=0;
    for (int i = 1; i < n; ++i) {
        e= arr[i];
        for (j = i; j > 0 &&  arr[j-1] > e; --j) {
            arr[j]= arr[j-1];
        }
        arr[j]=e;
        printArr(arr,n);
    }
}

/*使 arr[l+1,j] <v
 * arr[j+1,i) > v , i是当前正在的点
 * */
int __partition(int* arr , int l ,int r){
    //选定第一个元素为分界元素
    int v=arr[l];
    int j=l;
    for (int i = l+1; i <= r; ++i) {
        if(arr[i]< v){
            std::swap(arr[i],arr[j+1]);
            j++;
        }
    }
    std::swap(arr[l],arr[j]);
    return j;
}
/*
 * 对arr[l,r]进行排序使
 * arr[l,p-1] < arr[p] && arr[p+1,r] > arr[p]
 * */
void __quickSort(int* arr, int l,int r){
    if(l>=r)
        return;
    int p = __partition(arr,l,r);
    printArr(arr,8);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}

void quickSort(int* arr,int n){
    __quickSort(arr,0,n-1);

}
#endif //ALG_ALG_H
