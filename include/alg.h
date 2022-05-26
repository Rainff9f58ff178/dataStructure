//
// Created by rain on 2022/5/26.
//

#ifndef ALG_ALG_H
#define ALG_ALG_H
#include<vector>
#include <iostream>

void jo(){
    using namespace std;

    vector<char> arr;
    cout<<"一共a-z26人"<<endl;
    for (int i = 97; i < 123 ; ++i) {
        arr.push_back((char)i);
    }

    const int N=100;
    int m;
    int k;
    cout<<"从谁开始报数？"<<endl;
    cin>>k;
    int num=26;
    if(k>25 || k<0){
        cout<<"wrong range"<<endl;
        std::exit(1);
    }
    cout<<"数到几？"<<endl;
    cin>>m;
    bool isOuted[N]={false };
    int index=(k-1+m) % num;
    for (int i = 0; i < arr.size(); ++i) {
        int m_=m;
        cout<<arr[index]<<" ";
        isOuted[index]= true;
        while (m_--){
            index++;
            index=index%num;
            if(isOuted[index]== true){
                index++;
                index=index%num;
            }
        }
    }
}
#endif //ALG_ALG_H
