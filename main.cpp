#include <iostream>
#include "list.h"


void DoublyLinkListPrint(List<int> & l){
    
    size_t index = 0;
    for(auto & x : l){
        if(index == 0) {
            std::cout << x ;
        }else{
            std::cout << " " << x;
        }
        ++index ;
    }
    std::cout << std::endl;
}

void DoublyLinkListTest(){
    std::cout << "Creating a List " << std::endl;
    List<int>list1;

    std::cout << "Adding Items " << std::endl;
    for(int i = 0; i < 11 ; i++){
        list1.push_back(i*i);
    }
    std::cout<< "List1: "; DoublyLinkListPrint(list1);

    std::cout << "Front Item: " << list1.front() <<std::endl;
    std::cout << "Back Item: " << list1.back() <<std::endl;
    
    std::cout << "Add Item Front: " << std::endl;
    list1.push_front(-50);
    std::cout<< "List1: "; DoublyLinkListPrint(list1);

    std::cout << "Add Item Back: " << std::endl;
    list1.push_back(200);
    std::cout<< "List1: "; DoublyLinkListPrint(list1);

    std::cout << "Delete Item Front: " << std::endl;
    list1.pop_front();
    std::cout<< "List1: "; DoublyLinkListPrint(list1);

    std::cout << "Delete Item Back: " << std::endl;
    list1.pop_back();
    std::cout<< "List1: "; DoublyLinkListPrint(list1);
    
    //This is not working rn
    //std::cout << "Copy Constructor: " << std::endl;
    //List<int>list2;
    //list2 = list1;
    // std::cout<< "List2: "; DoublyLinkListPrint(list2);
}

int main(){

    DoublyLinkListTest();


    return 0;       
}