#include <iostream>
#include "tree.cpp"
#include <map>

std::string join(std::vector<std::string> vec, std::string separator) {
    std::string res = "";
    for (int x = 0; x < vec.size(); x++) {
        res += vec[x];

        if (x != vec.size() - 1) {
            res += separator;
        }
    }
    return res;
}

void dfs(Node node, int currentWeight, std::vector<std::string> visited, std::map<std::string, int>& paths) {
    visited.push_back(node.name);
    auto weight = currentWeight + node.weight;
    paths[join(visited, "-")] = weight;

    if (node.children.size() == 0) {
        return;
    }

    for (int x = 0; x < node.children.size(); x++) {
        dfs(*node.children[x], weight, visited, paths);
    }
}

struct Path {
    std::string depth;
    int weight; 
};

Path getHeaviestPath(Node tree) {
    std::map<std::string, int> paths = {};
    dfs(tree, 0, {}, paths);

    Path heaviest = {
        paths.begin()->first, 
        paths.begin()->second
    };

    for (auto el : paths) {
        if (el.second > heaviest.weight) {
            heaviest = {
                el.first,
                el.second
            };
        }
    }

    return heaviest;
}

int main() {
    auto tree = buildTree();
    auto heviestPath = getHeaviestPath(*tree);
    std::cout << heviestPath.depth << ": " << heviestPath.weight << std::endl;

    return 0;
}