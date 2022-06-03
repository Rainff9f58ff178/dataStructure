//
// Created by rain on 22-5-2.
//

#ifndef ALG_BST_HPP
#define ALG_BST_HPP

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

class BlanaceBST {
private:

public:

private:
};

#endif //ALG_BST_HPP
