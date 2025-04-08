#pragma once
#include <iostream>
#include <functional>

template<typename T>
class TreeNode {
public:
    T value;
    TreeNode<T>** children;
    int children_count;

    TreeNode(T val) : value(val), children(nullptr), children_count(0) {}
    ~TreeNode() {
        delete[] children;
    }
};

template<typename T>
class Tree {
private:
    TreeNode<T>* root;

    void delete_subtree(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < node->children_count; ++i) {
            delete_subtree(node->children[i]);
        }
        delete node;
    }

    void remove_child(TreeNode<T>* parent, TreeNode<T>* child) {
        if (parent == nullptr || child == nullptr) {
            return;
        }

        int new_count = parent->children_count - 1;
        TreeNode<T>** new_children = new TreeNode<T>*[new_count];
        int index = 0;

        for (int i = 0; i < parent->children_count; ++i) {
            if (parent->children[i] != child) {
                new_children[index++] = parent->children[i];
            }
        }

        delete[] parent->children;
        parent->children = new_children;
        parent->children_count = new_count;
    }

    TreeNode<T>* find(TreeNode<T>* node, std::function<bool(const T&)> compare) {
        if (node == nullptr) {
            return nullptr;
        }

        if (compare(node->value)) {
            return node;
        }

        for (int i = 0; i < node->children_count; ++i) {
            TreeNode<T>* found = find(node->children[i], compare);
            if (found != nullptr) {
                return found;
            }
        }
        return nullptr;
    }

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        delete_subtree(root);
    }

    TreeNode<T>* add_node(TreeNode<T>* parent, T value) {
        TreeNode<T>* new_node = new TreeNode<T>(value);
        if (parent == nullptr) {
            root = new_node;
        }
        else {
            TreeNode<T>** new_children = new TreeNode<T>*[parent->children_count + 1];
            for (int i = 0; i < parent->children_count; ++i) {
                new_children[i] = parent->children[i];
            }
            new_children[parent->children_count] = new_node;
            delete[] parent->children;
            parent->children = new_children;
            ++parent->children_count;
        }
        return new_node;
    }

    TreeNode<T>* get_node(TreeNode<T>* parent) {
		if (parent == nullptr) {
			return root;
        }
        else {
            return parent;
        }
    }

    void delete_node(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        if (node == root) {
            delete_subtree(root);
            root = nullptr;
        }
        else {
            for (int i = 0; i < node->children_count; ++i) {
                delete_subtree(node->children[i]);
            }
            remove_child(find_parent(root, node), node);
            delete node;
        }
    }

    TreeNode<T>* find(std::function<bool(const T&)> compare) {
        return find(root, compare);
    }

    void insert(TreeNode<T>* parent, T value, int index) {
        if (parent == nullptr) {
            return;
        }

        if (index < 0 || index > parent->children_count) {
            return;
        }

        TreeNode<T>* new_node = new TreeNode<T>(value);
        
        TreeNode<T>** new_children = new TreeNode<T>*[parent->children_count + 1];
        for (int i = 0; i < index; i++) {
            new_children[i] = parent->children[i];
        }

        new_children[index] = new_node;
        for (int i = index; i < parent->children_count; i++) {
            new_children[i + 1] = parent->children[i];
        }
        delete[] parent->children;
        parent->children = new_children;
        ++parent->children_count;
    }

    void sort(TreeNode<T>* node, std::function<bool(const T&, const T&)> compare = nullptr) {
        if (node == nullptr || node->children_count == 0) {
            return;
        }

        if (compare == nullptr) {
            compare = [](const T& a, const T& b) { return a < b; };
        }

        for (int i = 0; i < node->children_count - 1; i++) {
            for (int j = i + 1; j < node->children_count; j++) {
                if (!compare(node->children[i]->value, node->children[j]->value)) {
                    TreeNode<T>* temp = node->children[i];
                    node->children[i] = node->children[j];
                    node->children[j] = temp;
                }
            }
        }

        for (int i = 0; i < node->children_count; ++i) {
            sort(node->children[i], compare);
        }
    }

    int count(TreeNode<T>* node) {
        if (node == nullptr) {
            node = root;
        }

        if (node == nullptr) {
            return 0;
		}
        int total = 1; // Count the current node
        for (int i = 0; i < node->children_count; ++i) {
            total += count(node->children[i]);
        }
        return total;
    }

private:
    TreeNode<T>* find_parent(TreeNode<T>* node, TreeNode<T>* target) {
        if (node == nullptr || target == nullptr) {
            return nullptr;
        }

        for (int i = 0; i < node->children_count; ++i) {
            if (node->children[i] == target) {
                return node;
            }
            TreeNode<T>* found = find_parent(node->children[i], target);
            if (found) {
                return found;
            }
        }

        return nullptr;
    }
};
