#include <iostream>
#include "List.h"

int main()
{
    LinkedList<int> list;
    list.addToHead(4);
    list.addToHead(8);
    list.addToHead(999);
    list.show();

    std::cout << "\n\n";
    list.addToTail(888);
    list.addToTail(777);
    list.show();

    std::cout << "\n\n";
    list.deleteFromHead();
    list.show();

    std::cout << "\n\n";
    list.deleteFromTail();
    list.show();

    std::cout << "\n\n";
    //list.deleteAll();
    list.show();

    std::cout << "\n\n";
    list.reverse();
    list.show();

    list.addToTail(111);
    list.addToTail(222);
    list.addToTail(333);
    list.addToTail(444);
    std::cout << "\n\n";
    list.show();

    list.reverse();
    std::cout << "\n\n";
    list.show();


    list.insert(3, 34);
    std::cout << "\n\n";
    list.show();

    list.remove(3);
    std::cout << "\n\n";
    list.show();

    list.insert(1, 10000);
    std::cout << "\n\n";
    list.show();


    list.remove(6);
    std::cout << "\n\n";
    list.show();

    std::cout << "\n\n";
    std::cout << list.find(999) << std::endl;


    list.addToTail(333);
    list.addToTail(333);
    list.addToTail(333);
    list.addToTail(333);


    std::cout << "\n\n";
    std::cout << list.find(333, 565) << std::endl;

    list.show();

}
