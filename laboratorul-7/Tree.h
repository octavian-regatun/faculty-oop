#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node<T> *parentNode;
    Node<T> **childrenNodes;
    unsigned int childrenSize;
    unsigned int childrenCount;

    Node(Node<T> *parentNode, T data) {
        this->parentNode = parentNode;
        this->data = data;
        childrenCount = 0;
        childrenSize = 1;
        childrenNodes = new Node<T> *[1];
    }

    void resizeChildrenArray() {
        Node<T> **newChildrenArray = new Node<T> *[childrenSize * 2];

        for (int i = 0; i < childrenCount; i++)
            newChildrenArray[i] = childrenNodes[i];

        delete[] childrenNodes;
        childrenNodes = newChildrenArray;
        childrenSize *= 2;
    }

    ~Node() {
        std::cout << "Destructor" << std::endl;

        for (int i = 0; i < childrenCount; i++)
            delete childrenNodes[i];

        delete[] childrenNodes;
    }
};

template<typename T>
class Tree {
public:
    Node<T> *rootNode = nullptr;

    Tree() {
        rootNode = nullptr;
    }

    void add_node(Node<T> *parentNode, T data) {
        auto *newNode = new Node(parentNode, data);

        if (parentNode == nullptr) {
            rootNode = newNode;
            return;
        }

        if (parentNode->childrenCount + 1 > parentNode->childrenSize)
            parentNode->resizeChildrenArray();

        parentNode->childrenNodes[parentNode->childrenCount++] = newNode;
    }

    unsigned int count(Node<T> *node) {
        if (node == nullptr) {
            return count(rootNode);
        }

        unsigned int sum = 0;

        for (int i = 0; i < node->childrenCount; i++)
            sum += count(node->childrenNodes[i]);


        return sum + node->childrenCount;
    }

    Node<T> &get_node(Node<T> *parentNode, unsigned int index) {
        if (parentNode == nullptr) return *rootNode;

        return *(parentNode->childrenNodes[index]);
    }

    void insert(Node<T> *parentNode, unsigned int index, T data) {
        auto newNode = new Node(parentNode, data);

        if (parentNode->childrenCount + 1 > parentNode->childrenSize) parentNode->resizeChildrenArray();
        for (int i = parentNode->childrenCount; i > index; i--)
            parentNode->childrenNodes[i] = parentNode->childrenNodes[i - 1];
        parentNode->childrenNodes[index] = newNode;
        parentNode->childrenCount++;
    }

    void delete_node(Node<T> *node) {
        if (node->parentNode == nullptr) {
            delete node;
            return;
        }

        int index = -1;
        Node<T> *parentNode = node->parentNode;

        for (int i = 0; i < parentNode->childrenCount; i++)
            if (parentNode->childrenNodes[i] == node) {
                index = i;
                break;
            }

        for (int i = index; i < parentNode->childrenCount - 1; i++)
            parentNode->childrenNodes[i] = parentNode->childrenNodes[i + 1];

        parentNode->childrenCount--;

        delete node;
    }

    void sort(Node<T> *node, bool (*fn)(Node<T> *, Node<T> *)) {
        for (int i = 0; i < node->childrenCount - 1; i++) {
            for (int j = 0; j < node->childrenCount - i - 1; j++)
                if (fn(node->childrenNodes[i], node->childrenNodes[i + 1]))
                    std::swap(node->childrenNodes[i], node->childrenNodes[i + 1]);
        }
    }
};