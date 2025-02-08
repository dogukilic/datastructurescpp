#include <iostream>
#include "list.h"

int main(){

    List<int>list1;

    for(int i = 0; i<11 ; i++){
        list1.push_back(i*i);
    }

    for(auto & x : list1){
        std::cout << " " << x;
    }


    return 0;       
}