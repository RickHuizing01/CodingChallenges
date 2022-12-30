#include <iostream>
#include <vector>

struct Node {
    std::string name;
    int weight;
    std::vector<Node*> children;
};

Node* buildTree() {
    Node* a = new Node;
    a->name = "a";
    a->weight = 0;

    Node* b = new Node;
    b->name = "b";
    b-> weight = 3;
    a->children.push_back(b);

    Node* c = new Node;
    c->name = "c";
    c->weight = 5;
    a->children.push_back(c);

    Node* d = new Node;
    d->name = "d";
    d->weight = 8;
    a->children.push_back(d);

    Node* e = new Node;
    e->name = "e";
    e->weight = 2;
    d->children.push_back(e);

    Node* f = new Node;
    f->name= "f";
    f->weight = 4;
    d->children.push_back(f);

    Node* g = new Node;
    g->name = "g";
    g->weight = 1;
    e->children.push_back(g);

    Node* h = new Node;
    h->name = "h";
    h->weight = 1;
    e->children.push_back(h);

    return a;
}