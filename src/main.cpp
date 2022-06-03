#include <iostream>
#include<vector>
#include <string>
#include<map>
#include <chrono>
#include <cstdint>
#include<ctime>
#include "BST.hpp"
#include"dataSruct.h"
#include "alg.h"

int main()
{
    using namespace std;
    BST<int,int> t;
    t.insert(3,1);
    t.insert(1,1);
    t.insert(2,1);
    t.insert(4,1);
    t.levelOrder();
    t.remove(2);
    cout<<endl;
    t.levelOrder();
    return 0;
}
