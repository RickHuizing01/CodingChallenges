#include <iostream>
#include "tree.cpp"
#include <map>

std::string join(const std::vector<std::string> vec, const std::string separator) {
    std::string res = "";
    for (int x = 0; x < vec.size(); x++) {
        res += vec[x];

        if (x != vec.size() - 1) {
            res += separator;
        }
    }
    return res;
}

void dfs(const Node node, int current_weight, std::vector<std::string> visited, std::map<std::string, int>& paths) {
    visited.push_back(node.name);
    int weight = current_weight + node.weight;
    paths[join(visited, "-")] = weight;

    if (node.children.size() == 0) {
        return;
    }

    for (auto child_node : node.children) {
        dfs(*child_node, weight, visited, paths);
    }
}

struct Path {
    std::string depth;
    int weight; 
};

Path get_heaviest_path(const Node tree) {
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
    std::shared_ptr<const Node> tree = buid_tree();
    if (tree == nullptr) return 1;

    Path heviestPath = get_heaviest_path(*tree);
    std::cout << heviestPath.depth << ": " << heviestPath.weight << std::endl;

    return 0;
}