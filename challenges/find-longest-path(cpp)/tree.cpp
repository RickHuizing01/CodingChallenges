#include <iostream>
#include <vector>
#include <memory>

struct Node {
    std::string name;
    int weight;
    std::vector<std::shared_ptr<Node>> children;
};

std::shared_ptr<Node> buildTree() {
    std::shared_ptr<Node> a(new Node);
    a->name = "a";
    a->weight = 0;

    std::shared_ptr<Node> b(new Node);
    b->name = "b";
    b-> weight = 3;
    a->children.push_back(b);

    std::shared_ptr<Node> c(new Node);
    c->name = "c";
    c->weight = 5;
    a->children.push_back(c);

    std::shared_ptr<Node> d(new Node);
    d->name = "d";
    d->weight = 8;
    a->children.push_back(d);

    std::shared_ptr<Node> e(new Node);
    e->name = "e";
    e->weight = 2;
    d->children.push_back(e);

    std::shared_ptr<Node> f(new Node);
    f->name= "f";
    f->weight = 4;
    d->children.push_back(f);

    std::shared_ptr<Node> g(new Node);
    g->name = "g";
    g->weight = 1;
    e->children.push_back(g);

    std::shared_ptr<Node> h(new Node);
    h->name = "h";
    h->weight = 1;
    e->children.push_back(h);

    return a;
}