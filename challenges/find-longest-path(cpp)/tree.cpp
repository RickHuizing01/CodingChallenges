#include <iostream>
#include <vector>
#include <memory>

struct Node {
    std::string name;
    int weight;
    std::vector<std::shared_ptr<Node>> children;
};

std::shared_ptr<Node> buid_tree() {
    std::shared_ptr<Node> a = std::make_shared<Node>();
    if (a == nullptr) return a;
    a->name = "a";
    a->weight = 0;

    std::shared_ptr<Node> b = std::make_shared<Node>();
    if (b == nullptr) return a;
    b->name = "b";
    b-> weight = 3;
    a->children.push_back(b);

    std::shared_ptr<Node> c = std::make_shared<Node>();
     if (c == nullptr) return a;
    c->name = "c";
    c->weight = 5;
    a->children.push_back(c);

    std::shared_ptr<Node> d = std::make_shared<Node>();
    if (d == nullptr) return a;
    d->name = "d";
    d->weight = 8;
    a->children.push_back(d);

    std::shared_ptr<Node> e = std::make_shared<Node>();
    if (e == nullptr) return a;
    e->name = "e";
    e->weight = 2;
    d->children.push_back(e);

    std::shared_ptr<Node> f = std::make_shared<Node>();
    if (f == nullptr) return a;
    f->name= "f";
    f->weight = 4;
    d->children.push_back(f);

    std::shared_ptr<Node> g = std::make_shared<Node>();
    if (g == nullptr) return a;
    g->name = "g";
    g->weight = 1;
    e->children.push_back(g);

    std::shared_ptr<Node> h = std::make_shared<Node>();
    if (h == nullptr) return a;
    h->name = "h";
    h->weight = 1;
    e->children.push_back(h);

    return a;
}