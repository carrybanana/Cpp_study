#include <iostream>
#include <queue> // 用于层序遍历打印树

// 定义节点颜色
enum Color { RED, BLACK };

// 红黑树节点结构体
template <typename T>
struct Node {
    T data;
    bool color;
    Node<T> *parent, *left, *right;

    // 构造函数
    Node(T data) : data(data), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
};

// 红黑树类
template <typename T>
class RedBlackTree {
private:
    Node<T>* root;
    Node<T>* TNULL; // 哨兵空节点

    // // 初始化哨兵节点
    // void initializeNULLNode(Node<T>* node, Node<T>* parent) {
    //     node->data = 0; // 或任何默认值
    //     node->parent = parent;
    //     node->left = nullptr;
    //     node->right = nullptr;
    //     node->color = BLACK;
    // }

    // 左旋操作
    void leftRotate(Node<T>* x) {
        Node<T>* y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // 右旋操作
    void rightRotate(Node<T>* x) {
        Node<T>* y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    // 插入后修复红黑树性质
    void fixInsert(Node<T>* k) {
        Node<T>* u; // uncle节点
        while (k != root && k->parent->color == RED) {
            if (k->parent == k->parent->parent->right) { // 父节点是祖父节点的右孩子
                u = k->parent->parent->left; // 叔叔节点
                if (u->color == RED) {
                    // Case 1: 叔叔是红色 -> 重新着色
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        // Case 2: 叔叔是黑色，且当前节点是左孩子 -> 右旋
                        k = k->parent;
                        rightRotate(k);
                    }
                    // Case 3: 叔叔是黑色，且当前节点是右孩子 -> 左旋并重新着色
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            } else { // 父节点是祖父节点的左孩子 (与上面对称)
                u = k->parent->parent->right; // 叔叔节点

                if (u->color == RED) {
                    // Case 1
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        // Case 2
                        k = k->parent;
                        leftRotate(k);
                    }
                    // Case 3
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = BLACK; // 根节点始终为黑色
    }

    // 删除后修复红黑树性质
    void fixDelete(Node<T>* x) {
        Node<T>* s; // sibling节点
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == RED) {
                    // Case 1: 兄弟是红色
                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == BLACK && s->right->color == BLACK) {
                    // Case 2: 兄弟是黑色，且兄弟的两个孩子都是黑色
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->right->color == BLACK) {
                        // Case 3: 兄弟是黑色，兄弟的左孩子是红色，右孩子是黑色
                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    // Case 4: 兄弟是黑色，且兄弟的右孩子是红色
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else { // 与上面对称
                s = x->parent->left;
                if (s->color == RED) {
                    // Case 1
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == BLACK && s->left->color == BLACK) {
                    // Case 2
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->left->color == BLACK) {
                        // Case 3
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    // Case 4
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    // 辅助函数：用另一棵子树替换一棵子树
    void rbTransplant(Node<T>* u, Node<T>* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != TNULL) {  // ✅ 防止修改 TNULL 的 parent
            v->parent = u->parent;
        }
    }

    // 辅助函数：删除一个节点
    void deleteNodeHelper(Node<T>* node, T key) {
        Node<T>* z = TNULL;
        Node<T>* x, * y;
        z = search(key); // 查找要删除的节点

        if (z == TNULL) {
            std::cout << "Couldn't find key in the tree" << std::endl;
            return;
        }

        y = z;
        bool y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        } else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                if (x != TNULL) {  // ✅ 只有非 TNULL 才设置 parent
                    x->parent = y;
                }
            } else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == BLACK) {
            fixDelete(x);
        }
    }

public:
    // RedBlackTree() {
    //     TNULL = new Node<T>(T());
    //     TNULL->color = BLACK;
    //     TNULL->left = nullptr;
    //     TNULL->right = nullptr;
    //     root = TNULL;
    // }

    RedBlackTree() {
        TNULL = new Node<T>(T());  // 临时构造
        TNULL->parent = TNULL;
        TNULL->left = TNULL;
        TNULL->right = TNULL;
        TNULL->color = BLACK;
        root = TNULL;
    }

    ~RedBlackTree() {
        if (root != TNULL) {
            destroyTree(root);
        }
        delete TNULL; // TNULL 是单独分配的
    }

    void destroyTree(Node<T>* node) {
        if (node == TNULL) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    // // 查找操作
    // Node<T>* search(T k) {
    //     Node<T>* current = this->root;
    //     while (current != TNULL && k != current->data) {
    //         if (k < current->data) {
    //             current = current->left;
    //         } else {
    //             current = current->right;
    //         }
    //     }
    //     return current;
    // }

    // 查找
    Node<T>* search(T k) {
        Node<T>* current = root;
        while (current != TNULL && k != current->data) {
            current = (k < current->data) ? current->left : current->right;
        }
        return current; // 如果没找到，返回 TNULL
    }

    // 查找子树中的最小节点
    Node<T>* minimum(Node<T>* node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }

    // 插入操作
    void insert(T key) {
        Node<T>* node = new Node<T>(key);
        // 新增：将新节点的左右孩子指向TNULL
        node->left = TNULL;
        node->right = TNULL;

        Node<T>* y = TNULL;  // ✅ 改为 TNULL
        Node<T>* x = root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == TNULL) {  // 树为空
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        // 新节点颜色为红色
        node->color = RED;

        // 如果是根节点，直接变黑
        if (node->parent == TNULL) {
            node->color = BLACK;
            return;
        }

        // 如果祖父节点是 TNULL，无需修复
        if (node->parent->parent == TNULL) {
            return;
        }

        fixInsert(node);
    }

    // 删除操作
    void deleteNode(T data) {
        deleteNodeHelper(this->root, data);
    }

    // // 打印树（层序遍历）
    // void printTree() {
    //     if (root == TNULL) {
    //         std::cout << "Tree is empty." << std::endl;
    //         return;
    //     }

    //     std::queue<Node<T>*> q;
    //     q.push(root);

    //     while (!q.empty()) {
    //         Node<T>* curr = q.front();
    //         q.pop();

    //         std::cout << "Value: " << curr->data;
    //         std::cout << " Color: " << (curr->color == RED ? "RED" : "BLACK");

    //         if (curr->parent)
    //             std::cout << " Parent: " << curr->parent->data;

    //         if (curr->left != TNULL) {
    //             std::cout << " L-Child: " << curr->left->data;
    //             q.push(curr->left);
    //         }
    //         if (curr->right != TNULL) {
    //             std::cout << " R-Child: " << curr->right->data;
    //             q.push(curr->right);
    //         }
    //         std::cout << std::endl;
    //     }
    // }

    //  打印树
    void printTree() {
        if (root == TNULL) {
            std::cout << "Tree is empty.\n";
            return;
        }

        std::queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node<T>* curr = q.front(); q.pop();
                std::cout << curr->data << "(" << (curr->color ? "B" : "R") << ") ";

                if (curr->left != TNULL)  q.push(curr->left);
                if (curr->right != TNULL) q.push(curr->right);
            }
            std::cout << "\n"; // 按层换行
        }
    }

    // 供外部检查是否为 TNULL
    Node<T>* getTNULL() const {
        return TNULL;
    }

    RedBlackTree(const RedBlackTree&) = delete;
    RedBlackTree& operator=(const RedBlackTree&) = delete;
};
