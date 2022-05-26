//
// Created by rain on 22-5-2.
//

#ifndef ALG_BST_HPP
#define ALG_BST_HPP
#include<queue>
#include<iostream>
template<typename Key,typename Value>
class BST{
    int count;
    class Node{
    public:
        Node(Key key,Value value){
            this->key=key;
            this->value=value;
            this->leftNode= nullptr;
            this->rightNode= nullptr;
        }
        Node* leftNode;
        Node* rightNode;
        Key key;
        Value value;
    };
    Node* root;
public:
    BST(){
        count=0;
        root= nullptr;
    }
    void insert(Key key ,Value value){
        root= __insert(root,key,value);
    }

    void levelOrder(){
        if(root== nullptr) return;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node=q.front();
            std::cout<<node->key<<" "<<node->value<<std::endl;
            q.pop();
            if(node->leftNode)
                q.push(node->leftNode);
            if(node->rightNode)
                q.push(node->rightNode);
        }
    }
private:
    Node* __insert(Node* node,Key key,Value value){
        if(node == nullptr) {
            return new Node(key, value);
            count++;
        }

        if(key > node->key)
            node->rightNode= __insert(node->rightNode,key,value);
        if(key < node->key)
            node->leftNode = __insert(node->leftNode,key,value);

        if(key == node->key)
            node->value=value;

        return node;
    }
};

class BlanaceBST{
private:

public:

private:
};

#endif //ALG_BST_HPP
