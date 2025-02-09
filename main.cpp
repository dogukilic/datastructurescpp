#include <iostream>
#include "list.h"


void DoublyLinkListPrint(List<int> & l){
    
    size_t index = 0;
    if (l.size()== 0) return;
    for(auto & x : l){
        if(index == 0) {
            std::cout << x ;
        }else{
            std::cout << " " << x;
        }
        ++index ;
    }
}

void DoublyLinkListTest(){
    std::cout << "Creating a List " << std::endl;
    List<int>list1;

    std::cout << "Adding Items " << std::endl;
    for(int i = 0; i < 11 ; i++){
        list1.push_back(i*i);
    }
    std::cout<< "List1: "; DoublyLinkListPrint(list1); std::cout<< std::endl;

    std::cout << "Front Item: " << list1.front() <<std::endl;
    std::cout << "Back Item: " << list1.back() <<std::endl;
    
    std::cout << "Add Item Front: " << std::endl;
    list1.push_front(-50);
    std::cout<< "List1: "; DoublyLinkListPrint(list1); std::cout<< std::endl;

    std::cout << "Add Item Back: " << std::endl;
    list1.push_back(200);
    std::cout<< "List1: "; DoublyLinkListPrint(list1); std::cout<< std::endl;

    std::cout << "Delete Item Front: " << std::endl;
    list1.pop_front();
    std::cout<< "List1: "; DoublyLinkListPrint(list1); std::cout<< std::endl;

    std::cout << "Delete Item Back: " << std::endl;
    list1.pop_back();
    std::cout<< "List1: "; DoublyLinkListPrint(list1); std::cout<< std::endl;
    
    std::cout << "Copy Constructor: " << std::endl;
    List<int>list2 = list1;
    std::cout<< "List2: ";  DoublyLinkListPrint(list2); std::cout<< std::endl;

    std::cout << "Copy Assignment Operator: " << std::endl;
    List<int>list3;
    list3 = list1; list3.push_back(100000);
    std::cout<< "List3: ";  DoublyLinkListPrint(list3); std::cout<< std::endl;

    std::cout << "Move Constructor: " << std::endl;
    List<int>list4 = std::move(list2);
    std::cout << "List4: " ; DoublyLinkListPrint(list4); std::cout<< std::endl;
    std::cout << "List2: " ; DoublyLinkListPrint(list2); std::cout<< std::endl;

    std::cout << "Move Assignment Operator: " << std::endl;
    List<int>list5;
    list5 = std::move(list3); 
    std::cout<< "List5: ";  DoublyLinkListPrint(list5); std::cout<< std::endl;
    std::cout<< "List3: ";  DoublyLinkListPrint(list3); std::cout<< std::endl;

}

int main(){

    DoublyLinkListTest();


    return 0;       
}