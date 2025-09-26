#include "RedBlackTree.h"
#include <iostream>

int main() {
    RedBlackTree<int> rbt;

    rbt.insert(55);
    rbt.insert(40);
    rbt.insert(65);
    rbt.insert(60);
    rbt.insert(75);
    rbt.insert(57);

    std::cout << "Red-Black Tree after insertion:" << std::endl;
    rbt.printTree();

    std::cout << "\nDeleting 40..." << std::endl;
    std::cout << "\n" << std::string(40, '-') << "\n";
    rbt.deleteNode(40);

    std::cout << "\nRed-Black Tree after deleting 40:" << std::endl;
    rbt.printTree();

    std::cout << "\nSearching for 60..." << std::endl;
    Node<int>* found = rbt.search(60);
    if (found != rbt.getTNULL()) {
        std::cout << "Found " << found->data << " in the tree." << std::endl;
    } else {
        std::cout << "Did not find 60." << std::endl;
    }

    std::cout << "\nSearching for 100..." << std::endl;
    Node<int>* not_found = rbt.search(100);
    if (not_found != rbt.getTNULL()) {
        std::cout << "Found " << not_found->data << " in the tree." << std::endl;
    } else {
        std::cout << "Did not find 100." << std::endl;
    }

    return 0;
}
