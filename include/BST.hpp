//
// Created by rain on 22-5-2.
//

#ifndef ALG_BST_HPP
#define ALG_BST_HPP

#include <algorithm>
#include <exception>
#include<queue>
#include<iostream>

template<typename Key, typename Value>
class BST {
    int count;

    class Node {
    public:
        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->leftNode = nullptr;
            this->rightNode = nullptr;
        }

        Node *leftNode;
        Node *rightNode;
        Key key;
        Value value;
    };

    Node *root;
public:
    BST() {
        count = 0;
        root = nullptr;
    }
    int find(Key key,Value* value){
        if(root == nullptr)
            return -1;
        Node* current_node = root;

        while(current_node){
            if(key> current_node->key)
                current_node=current_node->rightNode;
            if(key< current_node->key)
                current_node=current_node->leftNode;
            if(key == current_node->key){
                std::cout<<current_node->value<<std::endl;
                *value= current_node->value;
                return 0;
            }

        }

        return -1;
    }
    void insert(Key key, Value value) {
        root = __insert(root, key, value);
    }

    void remove(Key key) {
        root = __remove(root, key);
    }

    void levelOrder() {
        if (root == nullptr) return;
        std::queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            std::cout << node->key << " " << node->value << std::endl;
            q.pop();
            if (node->leftNode)
                q.push(node->leftNode);
            if (node->rightNode)
                q.push(node->rightNode);
        }
    }




    void insert_without_recursion(Key key,Value value){
        if(root == nullptr){
            root=new Node(key,value);
            return;
        }
        Node* current_node = root;
        Node* pre_node = nullptr;
        while(current_node!=nullptr){
            if(key > current_node->key){
                pre_node=current_node;
                current_node=current_node->rightNode;

            }else if(key < current_node->key){
                pre_node=current_node;
                current_node=current_node->leftNode;
            }else{
                //key == current_node->key
                current_node->value=value;
                return;
            }
        }
        //now ,now the current_node==nullptr,and pre_node should 
        //be its parent node
        current_node = new Node(key,value);
        if(  current_node->key > pre_node->key ){
            pre_node->rightNode = current_node;
        }else{
//            current_node->key < pre_node->key
            pre_node->leftNode = current_node;
        }
        count++;
        
    }
private:
    Node *__remove(Node *node, Key key) {
        if (node == nullptr)
            return nullptr;
        if (key > node->key)
            node->rightNode = __remove(node->rightNode, key);
        if (key < node->key)
            node->leftNode = __remove(node->leftNode, key);
        if (key == node->key) {
            //四种情况
            if (node->leftNode == nullptr) {
                Node *right_node = node->rightNode;
                count--;
                delete node;
                return right_node;
            }
            else if (node->rightNode == nullptr) {
                Node *left_node = node->leftNode;
                count--;
                delete node;
                return left_node;
            } else {
                //左右节点都有
//                获得右子树上的最小节点（后继），把这个节点替换到删除节点上
                Node *succsessor = __getMin(node->rightNode);
                Node *newNode = new Node(succsessor->key, succsessor->value);
                __removeMin(node->rightNode);
                newNode->leftNode=node->leftNode;
                newNode->rightNode=node->rightNode;
                delete node;
                count--;
                return newNode;
            }
        }
        return  node;
    }

    /*
     * without recursion remove
     * */
    void __removeMin(Node *node) {
        Node *pre_node = nullptr;
        Node *current_node = node;
        while (current_node->leftNode) {
            pre_node = current_node;
            current_node = current_node->leftNode;
        }
        Node *node_right = current_node->rightNode;
        if(current_node==root)
            root=node_right;
        delete current_node;
        count--;
        if (pre_node)
            pre_node->leftNode = node_right;

    }

    Node *__getMin(Node *node) {
        while (node->leftNode)
            node = node->leftNode;
        return node;
    }

    Node *__insert(Node *node, Key key, Value value) {
        if (node == nullptr) {
            count++;
            return new Node(key, value);
        }

        if (key > node->key)
            node->rightNode = __insert(node->rightNode, key, value);
        if (key < node->key)
            node->leftNode = __insert(node->leftNode, key, value);

        if (key == node->key)
            node->value = value;

        return node;
    }
};

template <typename Key,typename Value>
class BlanaceBST {
private:
    class Node{
        public:
            Node(Key key,Value value){
                this->left_node=nullptr;
                this->right_node=nullptr;
                this->key=key;
                this->value=value;
            }
            Node(const Node& other_node){
                this->left_node=other_node.left_node;
                this->right_node=other_node.right_node;
                this->key=other_node.key;
                this->value=other_node.value;
            }
            Node* left_node;
            Node* right_node;
            Key key;
            Value value;
    };
    Node* root;
    int count;
public:

    BlanaceBST(){
        this->count=0;
        root=nullptr;
    }

    void insert(Key key,Value value){
        root=__insert(root,key, value);
    }


    void remove(Key key,Value value){
        root=__remove(root,key);
    }
    void preOrder(){
        __preOrder(root);
    }
private:
    Node* __remove(Node* node,Key key){
        if(node == nullptr)
            return nullptr;
        if(key>node->key){
            node->right_node=__remove(node->right_node,key);
            return __balance(node,key);
        }
        else if (key < node->key){
            node->left_node = __remove(node->left_node,key);
            return __balance(node, key);
        }
        else{
            // key == node->Key
            
            if(node->left_node==nullptr || node->right_node ==nullptr){
                Node* temp = node->left_node ? node->left_node : node->right_node;

                if(temp == nullptr){
                    temp=node;
                    node=nullptr;
                }
                else{
                    *node = *temp;
                }
                delete temp;
            }else{
                
                //has two child 
                Node* succsessor = __getMin(node->right_node);
                Node* newNode = new Node(succsessor->key,succsessor->value);
                __remove(node->right_node, succsessor->key);
                newNode->left_node= node->left_node;
                newNode->right_node = node->right_node;
                delete node;
                count --;
                return newNode;

            }


        }
        return node;
    }

    Node* __getMin(Node* node){
        while(node)
            node=node->left_node;
        return  node;
    }

    Node* __preOrder(Node* node){
        if(node == nullptr)
            return node;
        std::cout<<"key : "<<node->key <<std::endl;
        __preOrder(node->left_node);
        __preOrder(node->right_node);
    }
    Node* __insert(Node* node,Key key,Value value){
        if(node==nullptr){
            count++;
            return new Node(key,value);
        }
        if(key > node->key){
            node->right_node=__insert(node->right_node, key, value);
            // BALANCE OPERATION 
            return __balance(node,key);
        }
        else if (key < node->key){
            node->left_node=__insert(node->left_node, key, value);
            return __balance(node,key);
        }else{
            // key == node->key
            node->value=value;
        }
        return node;
    }
    Node* __balance(Node* node,Key key){
        int factor = __balance_factor(node);
        if(factor>= -1 && factor<= 1)
            return node;    

        //factor > 1 maen left_height > right_height
        if(factor>1 && key < node->left_node->key ){
            //LL case
            return ll_rotate(node);
        }else if(factor > 1 && key > node->left_node->key){
            return lr_rotate(node);
            //LR case
        }else if(factor < -1 && key > node->right_node->key){
            // RR case
            return rr_rotate(node);
        }else if (factor < -1 && key < node->right_node->key){
            //RL case 
            return rl_rotate(node);
        }   
        return node;
    }

    Node* rl_rotate(Node* node){
        ll_rotate(node->right_node);
        return rr_rotate(node);
    }
    Node* lr_rotate(Node* node){
        rr_rotate(node->left_node);
        return ll_rotate(node);
    }
    Node* rr_rotate(Node* node){
        Node* right_node = node->right_node;
        node->right_node =right_node->left_node;
        right_node->left_node = node;
        return right_node;
    }
    Node* ll_rotate(Node* node){
        Node* left_node = node->left_node;
        node->left_node = left_node->right_node;
        left_node->right_node = node;
        return left_node;
    }
    int __balance_factor(Node* node){
        return __height(node->left_node)-__height(node->right_node);
    }
    int __height(Node* node){
        if(node==nullptr)
            return 0;
        else{
            int left_side=__height(node->left_node);
            int right_side = __height(node->right_node);
            if(left_side > right_side)
                return left_side+1;
            else
                return right_side+1;
            
        }

    }







};

#endif //ALG_BST_HPP
