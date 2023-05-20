
/*
 * 
 * hash table store data in some rule
 *
 *
 * 基本思想：记录的存储位置与关键字之间对应关系
 *
 *
 * hash func
 *  Logc(i) = H(keyi);
 *
 * */


#include "BST.hpp"
#include <sys/types.h>
#include <vector>
#include<functional>
#include<memory>
template <typename Key,typename Value>
class HashTable{
public:
    std::vector<std::shared_ptr<BST<Key, Value>>> arr_;
    HashTable(){

        for(int i=0;i<256;++i){
            arr_.resize(256);
            arr_[i] = std::shared_ptr<BST<Key, Value>>(new BST<Key, Value>);
        }
    }


    int find(Key key,Value* value){
        std::hash<decltype(key)> hash_func;
        auto index = hash_func(key) % 256;
        auto bst_p = arr_[index];

        if(bst_p->find(key,value)==-1)
            return -1;
        return 0;
    }
    void insert(Key key ,Value value){
        std::hash<decltype(key)> hash_func;
        auto index = hash_func(key) % 256;
        auto bst_p = arr_[index];
        bst_p->insert(key,value);
    }









    



};
