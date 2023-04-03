#include <iostream>
#include "Temperature.cpp"
#include "Tree.h"

void ex1() {
    int a = 300_Kelvin;
    int b = 120_Fahrenheit;

    std::cout << a << std::endl << b;
}

void ex2() {
    Tree<int> tree;

    tree.add_node(nullptr, 0);
    tree.add_node(tree.rootNode, 5);
    tree.add_node(tree.rootNode, 1);
    tree.add_node(tree.rootNode, 3);
    tree.add_node(tree.rootNode, 2);

    tree.add_node(tree.rootNode->childrenNodes[0], 923);
    tree.add_node(tree.rootNode->childrenNodes[0], 924);
    tree.add_node(tree.rootNode->childrenNodes[0], 925);

    std::cout << tree.count(nullptr) << std::endl;


    tree.insert(tree.rootNode->childrenNodes[0], 3, 444);
    tree.insert(tree.rootNode->childrenNodes[0], 3, 455);
    std::cout << tree.get_node(tree.rootNode->childrenNodes[0], 4).data << std::endl;
    tree.insert(tree.rootNode->childrenNodes[0], 1, 900);


    auto sortCallback = [](Node<int> *a, Node<int> *b) -> bool {
        if (a->data < b->data) return true;
        return false;
    };

    tree.sort(tree.rootNode, sortCallback);

    auto findCallback = [](int data, Node<int> *node) -> bool {
        if (node->data == data) return true;
        return false;
    };

    auto foundNode = tree.find(455, findCallback);

    std::cout << foundNode->data<<std::endl;

    tree.delete_node(tree.rootNode->childrenNodes[0]);

    std::cout << tree.count(nullptr);

}

int main() {
    ex2();

    return 0;
}

