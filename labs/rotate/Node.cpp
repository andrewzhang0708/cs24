#include "Node.h"

// Node Function Implementations
Node::Node(const std::string& s) : data(s), left(nullptr), right(nullptr){};

void Node::addOne() {
    weight++;
};

void Node::removeOne() {
    weight--;
};

void Node::updateWeight() {
    weight = 1 + (left ? left->weight : 0) + (right ? right->weight : 0);
}