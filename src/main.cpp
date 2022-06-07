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
using namespace std;
int main() {
    int  arr[]={55,39,60,88,70,10,25,55};

    quickSort(arr,8);
    return 0;
}
