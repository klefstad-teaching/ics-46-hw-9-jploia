#include "ladder.h"
#include <iostream>
#include <queue>
#include <string>
#include <set>

void error(string word1, string word2, string msg) {
    std::cout << word1 << word2 << msg << '\n';
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    return false;
}

bool is_adjacent(const string& word1, const string& word2) {
    return false;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    std::queue<vector<std::string> > ladder_queue;
    std::vector<std::string> begin_ladder;
    begin_ladder.push_back(begin_word);
    ladder_queue.push(begin_ladder);
    std::set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<std::string> ladder = ladder_queue.front();
        ladder_queue.pop();
        std::string last_word = ladder.back();
        for (const auto& word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) != visited.end()) {
                    visited.insert(word);
                    vector<std::string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word) {
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    vector<std::string> empty;
    return empty;
}

void load_words(set<string> & word_list, const string& file_name) {
    return;
}

void print_word_ladder(const vector<string>& ladder) {
    if (!ladder.empty()) {
        std::cout << "Word ladder found: ";
        for (const auto& word : ladder) {
            std::cout << word << " ";
        }        
    } else {
        std::cout << "No word ladder found.";
    }
    std::cout << '\n';
}

void verify_word_ladder() {
    return;
}